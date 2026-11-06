/*
二叉树遍历的 Go 写法（前序 / 中序 / 后序 / 层序）

前序遍历：根 -> 左 -> 右
中序遍历：左 -> 根 -> 右
后序遍历：左 -> 右 -> 根
层序遍历：从上到下、从左到右，逐层访问

前三种用递归最直观，这里同时给出用切片模拟栈的迭代写法；
层序遍历则用切片模拟队列，每次处理完一层再处理下一层。

注：LeetCode 的 Go 判题环境会自动提供 TreeNode 定义，
这里把它写出来是为了让本文件可以独立运行、直接看到结果。
*/

package main

import "fmt"

// TreeNode 是二叉树节点。
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// preorderTraversal 前序遍历（递归）：根 -> 左 -> 右。
func preorderTraversal(root *TreeNode) []int {
	res := []int{}
	var dfs func(node *TreeNode)
	dfs = func(node *TreeNode) {
		if node == nil {
			return
		}
		res = append(res, node.Val) // 根
		dfs(node.Left)              // 左
		dfs(node.Right)             // 右
	}
	dfs(root)
	return res
}

// preorderTraversalIterative 前序遍历（迭代）：用切片当栈。
func preorderTraversalIterative(root *TreeNode) []int {
	res := []int{}
	if root == nil {
		return res
	}

	stack := []*TreeNode{root}
	for len(stack) > 0 {
		node := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		res = append(res, node.Val)

		// 栈是后进先出，所以先压右孩子、再压左孩子，出栈顺序才是左、右。
		if node.Right != nil {
			stack = append(stack, node.Right)
		}
		if node.Left != nil {
			stack = append(stack, node.Left)
		}
	}
	return res
}

// inorderTraversal 中序遍历（递归）：左 -> 根 -> 右。
func inorderTraversal(root *TreeNode) []int {
	res := []int{}
	var dfs func(node *TreeNode)
	dfs = func(node *TreeNode) {
		if node == nil {
			return
		}
		dfs(node.Left)              // 左
		res = append(res, node.Val) // 根
		dfs(node.Right)             // 右
	}
	dfs(root)
	return res
}

// inorderTraversalIterative 中序遍历（迭代）：先一路向左入栈，再弹出访问、转向右子树。
func inorderTraversalIterative(root *TreeNode) []int {
	res := []int{}
	stack := []*TreeNode{}
	cur := root

	for cur != nil || len(stack) > 0 {
		// 把当前节点及其所有左孩子压栈。
		for cur != nil {
			stack = append(stack, cur)
			cur = cur.Left
		}

		// 弹出栈顶访问，然后处理它的右子树。
		cur = stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		res = append(res, cur.Val)
		cur = cur.Right
	}
	return res
}

// postorderTraversal 后序遍历（递归）：左 -> 右 -> 根。
func postorderTraversal(root *TreeNode) []int {
	res := []int{}
	var dfs func(node *TreeNode)
	dfs = func(node *TreeNode) {
		if node == nil {
			return
		}
		dfs(node.Left)              // 左
		dfs(node.Right)             // 右
		res = append(res, node.Val) // 根
	}
	dfs(root)
	return res
}

// postorderTraversalIterative 后序遍历（迭代）：先按 根 -> 右 -> 左 收集，最后整体反转。
func postorderTraversalIterative(root *TreeNode) []int {
	res := []int{}
	if root == nil {
		return res
	}

	stack := []*TreeNode{root}
	for len(stack) > 0 {
		node := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		res = append(res, node.Val)

		// 先压左孩子、再压右孩子，得到的是 根 -> 右 -> 左。
		if node.Left != nil {
			stack = append(stack, node.Left)
		}
		if node.Right != nil {
			stack = append(stack, node.Right)
		}
	}

	// 反转后就是 左 -> 右 -> 根。
	for i, j := 0, len(res)-1; i < j; i, j = i+1, j-1 {
		res[i], res[j] = res[j], res[i]
	}
	return res
}

// levelOrder 层序遍历：用切片当队列，逐层收集结果。
func levelOrder(root *TreeNode) [][]int {
	res := [][]int{}
	if root == nil {
		return res
	}

	queue := []*TreeNode{root}
	for len(queue) > 0 {
		level := make([]int, 0, len(queue))
		next := make([]*TreeNode, 0, len(queue)*2)

		for _, node := range queue {
			level = append(level, node.Val)
			if node.Left != nil {
				next = append(next, node.Left)
			}
			if node.Right != nil {
				next = append(next, node.Right)
			}
		}

		res = append(res, level)
		queue = next
	}
	return res
}

func main() {
	// 构造示例二叉树：
	//        3
	//       / \
	//      9   20
	//         /  \
	//        15   7
	root := &TreeNode{
		Val:  3,
		Left: &TreeNode{Val: 9},
		Right: &TreeNode{
			Val:   20,
			Left:  &TreeNode{Val: 15},
			Right: &TreeNode{Val: 7},
		},
	}

	fmt.Println("前序遍历（递归）:", preorderTraversal(root))
	fmt.Println("前序遍历（迭代）:", preorderTraversalIterative(root))
	fmt.Println("中序遍历（递归）:", inorderTraversal(root))
	fmt.Println("中序遍历（迭代）:", inorderTraversalIterative(root))
	fmt.Println("后序遍历（递归）:", postorderTraversal(root))
	fmt.Println("后序遍历（迭代）:", postorderTraversalIterative(root))
	fmt.Println("层序遍历:", levelOrder(root))
}
