/*
二叉树遍历的 JS 写法（前序 / 中序 / 后序 / 层序）

前序遍历：根 -> 左 -> 右
中序遍历：左 -> 根 -> 右
后序遍历：左 -> 右 -> 根
层序遍历：从上到下、从左到右，逐层访问

前三种用递归最直观，这里同时给出用数组模拟栈的迭代写法；
层序遍历则用数组模拟队列，每次处理完一层再处理下一层。

注：LeetCode 的 JS 判题环境会自动提供 TreeNode 定义，
这里把它写出来是为了让本文件可以独立运行、直接看到结果。
*/

// TreeNode 是二叉树节点。
class TreeNode {
  constructor(val, left = null, right = null) {
    this.val = val;
    this.left = left;
    this.right = right;
  }
}

// preorderTraversal 前序遍历（递归）：根 -> 左 -> 右。
function preorderTraversal(root) {
  const res = [];
  const dfs = (node) => {
    if (node === null) {
      return;
    }
    res.push(node.val); // 根
    dfs(node.left); // 左
    dfs(node.right); // 右
  };
  dfs(root);
  return res;
}

// preorderTraversalIterative 前序遍历（迭代）：用数组当栈。
function preorderTraversalIterative(root) {
  const res = [];
  if (root === null) {
    return res;
  }

  const stack = [root];
  while (stack.length > 0) {
    const node = stack.pop();
    res.push(node.val);

    // 栈是后进先出，所以先压右孩子、再压左孩子，出栈顺序才是左、右。
    if (node.right !== null) {
      stack.push(node.right);
    }
    if (node.left !== null) {
      stack.push(node.left);
    }
  }
  return res;
}

// inorderTraversal 中序遍历（递归）：左 -> 根 -> 右。
function inorderTraversal(root) {
  const res = [];
  const dfs = (node) => {
    if (node === null) {
      return;
    }
    dfs(node.left); // 左
    res.push(node.val); // 根
    dfs(node.right); // 右
  };
  dfs(root);
  return res;
}

// inorderTraversalIterative 中序遍历（迭代）：先一路向左入栈，再弹出访问、转向右子树。
function inorderTraversalIterative(root) {
  const res = [];
  const stack = [];
  let cur = root;

  while (cur !== null || stack.length > 0) {
    // 把当前节点及其所有左孩子压栈。
    while (cur !== null) {
      stack.push(cur);
      cur = cur.left;
    }

    // 弹出栈顶访问，然后处理它的右子树。
    cur = stack.pop();
    res.push(cur.val);
    cur = cur.right;
  }
  return res;
}

// postorderTraversal 后序遍历（递归）：左 -> 右 -> 根。
function postorderTraversal(root) {
  const res = [];
  const dfs = (node) => {
    if (node === null) {
      return;
    }
    dfs(node.left); // 左
    dfs(node.right); // 右
    res.push(node.val); // 根
  };
  dfs(root);
  return res;
}

// postorderTraversalIterative 后序遍历（迭代）：先按 根 -> 右 -> 左 收集，最后整体反转。
function postorderTraversalIterative(root) {
  const res = [];
  if (root === null) {
    return res;
  }

  const stack = [root];
  while (stack.length > 0) {
    const node = stack.pop();
    res.push(node.val);

    // 先压左孩子、再压右孩子，得到的是 根 -> 右 -> 左。
    if (node.left !== null) {
      stack.push(node.left);
    }
    if (node.right !== null) {
      stack.push(node.right);
    }
  }

  // 反转后就是 左 -> 右 -> 根。
  return res.reverse();
}

// levelOrder 层序遍历：用数组当队列，逐层收集结果。
function levelOrder(root) {
  const res = [];
  if (root === null) {
    return res;
  }

  let queue = [root];
  while (queue.length > 0) {
    const level = [];
    const next = [];

    for (const node of queue) {
      level.push(node.val);
      if (node.left !== null) {
        next.push(node.left);
      }
      if (node.right !== null) {
        next.push(node.right);
      }
    }

    res.push(level);
    queue = next;
  }
  return res;
}

// 构造示例二叉树：
//        3
//       / \
//      9   20
//         /  \
//        15   7
const root = new TreeNode(
  3,
  new TreeNode(9),
  new TreeNode(20, new TreeNode(15), new TreeNode(7))
);

console.log('前序遍历（递归）:', preorderTraversal(root));
console.log('前序遍历（迭代）:', preorderTraversalIterative(root));
console.log('中序遍历（递归）:', inorderTraversal(root));
console.log('中序遍历（迭代）:', inorderTraversalIterative(root));
console.log('后序遍历（递归）:', postorderTraversal(root));
console.log('后序遍历（迭代）:', postorderTraversalIterative(root));
console.log('层序遍历:', levelOrder(root));
