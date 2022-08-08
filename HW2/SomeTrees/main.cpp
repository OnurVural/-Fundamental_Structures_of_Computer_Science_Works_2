#include <iostream>
#include "BinarySearchTree.h"
#include "BinaryNode.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    BinarySearchTree bst;

    cout << "PREORDER: " << endl;
    bst.preorderTraverse();
    cout << "INORDER: " << endl;
    bst.inorderTraverse();
    cout << "POSTORDER: " << endl;
    bst.postorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "LEVELORDER: " << endl;
    bst.levelorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "Is empty? " << bst.isEmpty() << endl;
    cout << "Height is: " << bst.getHeight() << endl;
    cout << "Number of nodes:" << bst.getNumberOfNodes() << endl;
    cout << "Addition succesfull? " << bst.add(7) << endl;
    cout << "Addition succesfull? " << bst.add(5) << endl;
    cout << "Addition succesfull? " << bst.add(5) << endl;
    cout << "Addition succesfull? " << bst.add(34) << endl;
    cout << "Addition succesfull? " << bst.add(4) << endl;
    cout << "Addition succesfull? " << bst.add(6) << endl;
    cout << "Addition succesfull? " << bst.add(10) << endl;
    cout << "Addition succesfull? " << bst.add(40) << endl;
    cout << "Height is: " << bst.getHeight() << endl;
    cout << "Number of nodes: " << bst.getNumberOfNodes() << endl;
    cout << "PREORDER: " << endl;
    bst.preorderTraverse();
    cout << "INORDER: " << endl;
    bst.inorderTraverse();
    cout << "POSTORDER: " << endl;
    bst.postorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "LEVELORDER: " << endl;
    bst.levelorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY" << endl;
    cout << "SPAN: " << endl;
    cout << "The number of nodes within range is: " << bst.span(4,10) << endl;
    cout << "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY" << endl;

    cout << endl;
    cout << "666666666666666666666666666666666666666666666666666666666666666666666666666666666666" << endl;
    bst.mirror();
    cout << "PREORDER: " << endl;
    bst.preorderTraverse();
    cout << "INORDER: " << endl;
    bst.inorderTraverse();
    cout << "POSTORDER: " << endl;
    bst.postorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "LEVELORDER: " << endl;
    bst.levelorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY" << endl;
    cout << "SPAN: " << endl;
    cout << "The number of nodes within range is: " << bst.span(4,10) << endl;
    cout << "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY" << endl;
    cout << "666666666666666666666666666666666666666666666666666666666666666666666666666666666666" << endl;
    cout << endl;

    cout << endl;
    cout << "666666666666666666666666666666666666666666666666666666666666666666666666666666666666" << endl;
    bst.mirror();
    cout << "PREORDER: " << endl;
    bst.preorderTraverse();
    cout << "INORDER: " << endl;
    bst.inorderTraverse();
    cout << "POSTORDER: " << endl;
    bst.postorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "LEVELORDER: " << endl;
    bst.levelorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY" << endl;
    cout << "SPAN: " << endl;
    cout << "The number of nodes within range is: " << bst.span(4,10) << endl;
    cout << "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY" << endl;
    cout << "666666666666666666666666666666666666666666666666666666666666666666666666666666666666" << endl;
    cout << endl;


    cout << "Deletion succesfull? " << bst.remove(34) << endl;
    cout << "Deletion succesfull? " << bst.remove(48) << endl;
    cout << "Deletion succesfull? " << bst.remove(5) << endl;

    cout << "Contains? " << bst.contains(34) << endl;
    cout << "Contains? " << bst.contains(7) << endl;

    cout << "PREORDER: " << endl;
    bst.preorderTraverse();
    cout << "INORDER: " << endl;
    bst.inorderTraverse();
    cout << "POSTORDER: " << endl;
    bst.postorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "LEVELORDER: " << endl;
    bst.levelorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;

    cout << endl;
    cout << "666666666666666666666666666666666666666666666666666666666666666666666666666666666666" << endl;
    bst.mirror();
    cout << "PREORDER: " << endl;
    bst.preorderTraverse();
    cout << "INORDER: " << endl;
    bst.inorderTraverse();
    cout << "POSTORDER: " << endl;
    bst.postorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "LEVELORDER: " << endl;
    bst.levelorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY" << endl;
    cout << "SPAN: " << endl;
    cout << "The number of nodes within range is: " << bst.span(4,10) << endl;
    cout << "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY" << endl;
    cout << "666666666666666666666666666666666666666666666666666666666666666666666666666666666666" << endl;
    cout << endl;

    cout << endl;
    cout << "666666666666666666666666666666666666666666666666666666666666666666666666666666666666" << endl;
    bst.mirror();
    cout << "PREORDER: " << endl;
    bst.preorderTraverse();
    cout << "INORDER: " << endl;
    bst.inorderTraverse();
    cout << "POSTORDER: " << endl;
    bst.postorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "LEVELORDER: " << endl;
    bst.levelorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY" << endl;
    cout << "SPAN: " << endl;
    cout << "The number of nodes within range is: " << bst.span(4,10) << endl;
    cout << "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY" << endl;
    cout << "666666666666666666666666666666666666666666666666666666666666666666666666666666666666" << endl;
    cout << endl;
    cout << "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY" << endl;
    cout << "SPAN: " << endl;
    cout << "The number of nodes within range is: " << bst.span(0,4) << endl;
    cout << "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY" << endl;

    cout << endl;
    cout << endl;
    cout << "LETS EMPTY IT COMPLETELY" << endl;
    cout << "Deletion succesfull? " << bst.remove(7) << endl;
    cout << "Deletion succesfull? " << bst.remove(40) << endl;
    cout << "Deletion succesfull? " << bst.remove(10) << endl;
    cout << "Deletion succesfull? " << bst.remove(6) << endl;
    cout << "Deletion succesfull? " << bst.remove(4) << endl;
    cout << "Is empty? " << bst.isEmpty() << endl;
    cout << "Height is: " << bst.getHeight() << endl;
    cout << "Number of nodes:" << bst.getNumberOfNodes() << endl;
    cout << "PREORDER: " << endl;
    bst.preorderTraverse();
    cout << "INORDER: " << endl;
    bst.inorderTraverse();
    cout << "POSTORDER: " << endl;
    bst.postorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "LEVELORDER: " << endl;
    bst.levelorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "The number of nodes within range is: " << bst.span(4,10) << endl;
    cout << endl;
    cout << "AFTER MIRROR?" << endl;
    bst.mirror();
    cout << "Is empty? " << bst.isEmpty() << endl;
    cout << "Height is: " << bst.getHeight() << endl;
    cout << "Number of nodes:" << bst.getNumberOfNodes() << endl;
    cout << "PREORDER: " << endl;
    bst.preorderTraverse();
    cout << "INORDER: " << endl;
    bst.inorderTraverse();
    cout << "POSTORDER: " << endl;
    bst.postorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "LEVELORDER: " << endl;
    bst.levelorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "The number of nodes within range is: " << bst.span(4,10) << endl;
    cout << endl;

    cout << "AFTER RECOVERY?" << endl;
    bst.add(3);
    bst.add(2);
    bst.add(7);
    cout << "Is empty? " << bst.isEmpty() << endl;
    cout << "Height is: " << bst.getHeight() << endl;
    cout << "Number of nodes:" << bst.getNumberOfNodes() << endl;
    cout << "PREORDER: " << endl;
    bst.preorderTraverse();
    cout << "INORDER: " << endl;
    bst.inorderTraverse();
    cout << "POSTORDER: " << endl;
    bst.postorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "LEVELORDER: " << endl;
    bst.levelorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "The number of nodes within range is: " << bst.span(4,10) << endl;
    cout << endl;







    cout << endl;
    cout << "---CHECK TREE 2----" << endl;
    cout << endl;
    BinarySearchTree bst2;
    cout << "Is empty? " << bst2.isEmpty() << endl;
    cout << "Height is: " << bst2.getHeight() << endl;
    cout << "Number of nodes:" << bst2.getNumberOfNodes() << endl;
    cout << "Addition succesfull? " << bst2.add(31) << endl;
    cout << "Addition succesfull? " << bst2.add(7) << endl;
    cout << "Addition succesfull? " << bst2.add(56) << endl;
    cout << "Addition succesfull? " << bst2.add(2) << endl;
    cout << "Addition succesfull? " << bst2.add(1) << endl;
    cout << "Addition succesfull? " << bst2.add(41) << endl;
    cout << "Addition succesfull? " << bst2.add(45) << endl;
    cout << "Addition succesfull? " << bst2.add(10) << endl;
    cout << "Addition succesfull? " << bst2.add(70) << endl;
    cout << "Addition succesfull? " << bst2.add(42) << endl;
    cout << "Addition succesfull? " << bst2.add(38) << endl;
    cout << "Addition succesfull? " << bst2.add(9) << endl;
    cout << "Is empty? " << bst2.isEmpty() << endl;
    cout << "Height is: " << bst2.getHeight() << endl;
    cout << "Number of nodes:" << bst2.getNumberOfNodes() << endl;

    cout << "PREORDER: " << endl;
    bst2.preorderTraverse();
    cout << "INORDER: " << endl;
    bst2.inorderTraverse();
    cout << "POSTORDER: " << endl;
    bst2.postorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "LEVELORDER: " << endl;
    bst2.levelorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY" << endl;
    cout << "SPAN: " << endl;
    cout << "The number of nodes within range is: " << bst2.span(1,10) << endl;
    cout << "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY" << endl;
    cout << endl;

    cout << "Deletion succesfull? " << bst2.remove(1) << endl;
    cout << "Deletion succesfull? " << bst2.remove(45) << endl;
    cout << "Deletion succesfull? " << bst2.remove(56) << endl;
    cout << "Deletion succesfull? " << bst2.remove(44) << endl;
    cout << "Deletion succesfull? " << bst2.remove(7) << endl;

    cout << "Is empty? " << bst2.isEmpty() << endl;
    cout << "Height is: " << bst2.getHeight() << endl;
    cout << "Number of nodes:" << bst2.getNumberOfNodes() << endl;
    cout << "PREORDER: " << endl;
    bst2.preorderTraverse();
    cout << "INORDER: " << endl;
    bst2.inorderTraverse();
    cout << "POSTORDER: " << endl;
    bst2.postorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "LEVELORDER: " << endl;
    bst2.levelorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY" << endl;
    cout << "SPAN: " << endl;
    cout << "The number of nodes within range is: " << bst2.span(1,10) << endl;
    cout << "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY" << endl;
    cout << endl;
    cout << "Contains? " << bst2.contains(41) << endl;
    cout << "Contains? " << bst2.contains(7) << endl;
     cout << "AFTER MIRROR?" << endl;
     bst2.mirror();
     cout << "Is empty? " << bst2.isEmpty() << endl;
    cout << "Height is: " << bst2.getHeight() << endl;
    cout << "Number of nodes:" << bst2.getNumberOfNodes() << endl;
    cout << "PREORDER: " << endl;
    bst2.preorderTraverse();
    cout << "INORDER: " << endl;
    bst2.inorderTraverse();
    cout << "POSTORDER: " << endl;
    bst2.postorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "LEVELORDER: " << endl;
    bst2.levelorderTraverse();
    cout << "XXXXXXXXXXXXXXXXXXXX" << endl;
    cout << "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY" << endl;
    cout << "SPAN: " << endl;
    cout << "The number of nodes within range is: " << bst2.span(1,10) << endl;
    cout << "YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY" << endl;
    cout << endl;



    return 0;
}
