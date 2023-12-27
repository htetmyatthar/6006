class Doubly_Linked_List_Node:
    def __init__(self, x):
        self.item = x
        self.prev = None
        self.next = None

    def later_node(self, i):
        if i == 0: return self
        assert self.next
        return self.next.later_node(i - 1)

class Doubly_Linked_List_Seq:
    def __init__(self):
        self.head = None
        self.tail = None

    def __iter__(self):
        node = self.head
        while node:
            yield node.item
            node = node.next

    def __str__(self):
        return '-'.join([('(%s)' % x) for x in self])

    def build(self, X):
        for a in X:
            self.insert_last(a)

    def get_at(self, i):
        node = self.head.later_node(i)
        return node.item

    def set_at(self, i, x):
        node = self.head.later_node(i)
        node.item = x

    def insert_first(self, x):
        # doubly linked list
        # make a new node
        node = Doubly_Linked_List_Node(x)
        if self.head is None:
            self.head = node
            self.tail = node
        # add this node's next to the this sequence head
        else:
            node.next = self.head
            self.head.prev = node
            # let this sequence's head to be the node's previous one
            self.head = node

    def insert_last(self, x):
        # douobly linked list
        # make a new node
        node = Doubly_Linked_List_Node(x)
        if self.tail is None:
            self.head = node
            self.tail = node
        else:
            node.prev = self.tail
            self.tail.next = node
            self.tail = node

    def delete_first(self):
        assert self.head
        x = self.head.item
        self.head = self.head.next
        if self.head is None: self.tail = None
        else: self.head.prev = None
        return x

    def delete_last(self):
        assert self.tail
        x = self.tail.item
        self.tail = self.tail.prev
        if self.tail is None: self.head = None
        else: self.tail.next = None
        return x

    def remove(self, x1, x2):
        L2 = Doubly_Linked_List_Seq()
        # make the head the first element to remove
        L2.head = x1
        # make the tail the last element to remove
        L2.tail = x2
        if x1 == self.head:
            self.head = x2.next
        else:
            # removing inclusively both x1 and x2
            x1.prev.next = x2.next
        if x2 == self.tail:
            self.tail = x1.prev
        else:
            # removing inclusively both x1 and x2
            x2.next.prev = x1.prev
        # remove the pointers from the removing sequence
        x1.prev = None
        x2.next = None
        return L2

    def splice(self, x, L2):
        xn = x.next

        # x1 and x2 are first and last elements of the L2 sequence
        x1 = L2.head
        x2 = L2.tail

        L2.head = None
        L2.tail = None

        #
        x1.prev = x
        x.next = x1
        x2.next = xn

        if xn:
            xn.prev = x2
        else:
            self.tail = x2
