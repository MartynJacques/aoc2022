import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;

public class PartOne {

  static class Node {

    Node parent;
    List<Node> children = new ArrayList<>();
    String name;
    String type;
    int size;

    Node(String name, String type) {
      this.name = name;
      this.type = type;
    }

    Node(String name, String type, int size) {
      this.name = name;
      this.size = size;
      this.type = type;
    }
  }

  private static void print(Node node, String s) {
    System.out.println(s + "-" + node.name);
    for (Node child : node.children) {
      print(child, s + " ");
    }
  }

  private static Node buildGraph() {
    Node graph = new Node("/", "DIR");
    graph.parent = graph;

    Node current = graph;
    String file = "input.txt";
    try (BufferedReader br = new BufferedReader(new FileReader(file))) {
      String line;
      while ((line = br.readLine()) != null) {
        if (line.startsWith("dir")) {
          String name = line.split(" ")[1];
          Node newNode = new Node(name, "DIR");
          newNode.parent = current;
          current.children.add(newNode);
        } else if (line.equals("$ cd ..")) {
          current = current.parent;
        } else if (line.startsWith(("$ cd"))) {
          String name = line.split(" ")[2];
          for (Node child : current.children) {
            if (child.name.equals(name)) {
              current = child;
              break;
            }
          }
        } else if (!line.startsWith("$ ls")) {
          // We have a number here
          String[] lineSplit = line.split(" ");
          String name = lineSplit[1];
          int size = Integer.parseInt(lineSplit[0]);
          Node newNode = new Node(name, "FILE", size);
          newNode.parent = current;
          current.children.add(newNode);
        }
      }
    } catch (Exception e) {
      // do nothing
    }
    return graph;
  }

  static List<Integer> sizes = new ArrayList<>();

  private static int size(Node node) {
    if (node.type == "FILE") {
      return node.size;
    }
    int size = 0;
    for (Node child : node.children) {
      size += size(child);
    }
    if (size < 100000) {
      sizes.add(size);
    }
    return size;
  }

  public static void main(String[] args) {
    Node graph = buildGraph();
    // print(graph, "");
    size(graph);
    int total = 0;
    for (int size : sizes) {
      total += size;
    }
    System.out.println(total);
  }
}
