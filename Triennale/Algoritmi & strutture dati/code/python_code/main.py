import matplotlib.pyplot as plt
import networkx as nx

class TreeNode:
    """Classe per un nodo dell'albero binario di ricerca"""
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BinarySearchTree:
    """Classe per gestire un albero binario di ricerca"""
    def __init__(self):
        self.root = None

    def build_from_sorted_list(self, sorted_values):
        """Costruisce un BST bilanciato da una lista ordinata in maniera ricorsiva"""
        def build_subtree(start, end):
            if start > end:
                return None
            mid = (start + end) // 2
            node = TreeNode(sorted_values[mid])
            node.left = build_subtree(start, mid - 1)
            node.right = build_subtree(mid + 1, end)
            return node

        self.root = build_subtree(0, len(sorted_values) - 1)

    def draw_tree(self):
        """Disegna l'albero binario usando solo NetworkX e Matplotlib"""
        if not self.root:
            print("L'albero è vuoto!")
            return

        graph = nx.DiGraph()
        positions = {}

        def add_nodes_edges(node, x, y, dx):
            """Aggiunge nodi e archi con posizioni calcolate"""
            if node:
                graph.add_node(node.value)
                positions[node.value] = (x, y)
                if node.left:
                    graph.add_edge(node.value, node.left.value)
                    add_nodes_edges(node.left, x - dx, y - 1, dx / 2)
                if node.right:
                    graph.add_edge(node.value, node.right.value)
                    add_nodes_edges(node.right, x + dx, y - 1, dx / 2)

        # Inizializza il layout con la radice al centro
        add_nodes_edges(self.root, x=0, y=0, dx=1)

        # Disegna il grafo con Matplotlib
        nx.draw(graph, positions, with_labels=True, node_size=2000, node_color="lightblue", font_size=10, font_weight="bold")
        plt.title("Albero Binario di Ricerca (BST)")
        plt.show()

    # Le tre funzioni sottostanti servono per verificare se l'albero è completo
    def get_height(self):
        """Restituisce l'altezza dell'albero"""
        def get_subtree_height(node):
            if not node:
                return 0
            return 1 + max(get_subtree_height(node.left), get_subtree_height(node.right))

        return get_subtree_height(self.root)
    
    def is_complete_rec(self, node):
        if not node:
            return 0
        if not node.left and not node.right:
            return 1
        return self.is_complete_rec(node.left) + self.is_complete_rec(node.right)
        

    def is_complete(self):
        """Verifica se l'albero è completo"""
        if not self.root:
            return True
        tot = 2**(self.get_height() - 1)
        print(self.get_height())
        print(tot)
        return self.is_complete_rec(self.root) == tot


# Uso del programma
if __name__ == "__main__":
    # Lista ordinata di numeri da 1 a 63
    sorted_values = list(range(1, 64))

    # Creazione dell'albero binario di ricerca
    bst = BinarySearchTree()
    bst.build_from_sorted_list(sorted_values)

    print(bst.is_complete())
    # Disegno dell'albero
    bst.draw_tree()
