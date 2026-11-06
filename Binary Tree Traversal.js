/*
二叉树遍历的 JS 写法（前序 / 中序 / 后序 / 层序）

前序遍历：根 -> 左 -> 右
中序遍历：左 -> 根 -> 右
后序遍历：左 -> 右 -> 根
层序遍历：从上到下、从左到右，逐层访问

前三种用递归最直观，这里同时给出用数组模拟栈的迭代写法；
层序遍历则用数组模拟队列，每次处理完一层再处理下一层。

复杂度（n 为节点数，h 为树高，w 为最大层宽）：
- 递归写法：时间 O(n)，递归调用栈占 O(h)，链状树最坏为 O(n)
- 迭代写法：时间 O(n)，显式栈占 O(h)，链状树最坏为 O(n)
- 层序遍历：时间 O(n)，队列最多同时保存一层节点，空间 O(w)

注：LeetCode 的 JS 判题环境会自动提供 TreeNode 定义，
这里把它写出来是为了让本文件可以独立运行、直接看到结果。
*/

// TreeNode 是二叉树节点：val 存值，left / right 分别指向左右孩子。
class TreeNode {
  constructor(val, left = null, right = null) {
    this.val = val;
    this.left = left;
    this.right = right;
  }
}

/**
 * 前序遍历（递归）：根 -> 左 -> 右。
 * @param {TreeNode|null} root 二叉树根节点
 * @returns {number[]} 前序遍历得到的节点值
 */
function preorderTraversal(root) {
  const res = [];
  const dfs = (node) => {
    if (node === null) {
      return; // 空节点直接回溯
    }
    res.push(node.val); // 根：进入节点就先记录
    dfs(node.left); // 左：递归处理左子树
    dfs(node.right); // 右：递归处理右子树
  };
  dfs(root);
  return res;
}

/**
 * 前序遍历（迭代）：用数组当栈，先访问根，再依次处理右、左孩子。
 * @param {TreeNode|null} root 二叉树根节点
 * @returns {number[]} 前序遍历得到的节点值
 */
function preorderTraversalIterative(root) {
  const res = [];
  if (root === null) {
    return res;
  }

  // 用数组模拟栈：push / pop 都在尾部操作，均摊 O(1)。
  const stack = [root];
  while (stack.length > 0) {
    const node = stack.pop();
    res.push(node.val); // 出栈即访问

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

/**
 * 中序遍历（递归）：左 -> 根 -> 右。
 * @param {TreeNode|null} root 二叉树根节点
 * @returns {number[]} 中序遍历得到的节点值
 */
function inorderTraversal(root) {
  const res = [];
  const dfs = (node) => {
    if (node === null) {
      return;
    }
    dfs(node.left); // 左：先把左子树走完
    res.push(node.val); // 根：左子树访问完再记录当前节点
    dfs(node.right); // 右：最后处理右子树
  };
  dfs(root);
  return res;
}

/**
 * 中序遍历（迭代）：先一路向左入栈，再弹出访问、转向右子树。
 * 对二叉搜索树来说，这样得到的序列是升序的。
 * @param {TreeNode|null} root 二叉树根节点
 * @returns {number[]} 中序遍历得到的节点值
 */
function inorderTraversalIterative(root) {
  const res = [];
  const stack = [];
  let cur = root;

  while (cur !== null || stack.length > 0) {
    // 把当前节点及其所有左孩子压栈，直到没有左孩子为止。
    while (cur !== null) {
      stack.push(cur);
      cur = cur.left;
    }

    // 此时栈顶就是当前子树里最左的节点，弹出并访问。
    cur = stack.pop();
    res.push(cur.val);

    // 然后转向右子树，重复上面的过程。
    cur = cur.right;
  }
  return res;
}

/**
 * 后序遍历（递归）：左 -> 右 -> 根。
 * @param {TreeNode|null} root 二叉树根节点
 * @returns {number[]} 后序遍历得到的节点值
 */
function postorderTraversal(root) {
  const res = [];
  const dfs = (node) => {
    if (node === null) {
      return;
    }
    dfs(node.left); // 左
    dfs(node.right); // 右
    res.push(node.val); // 根：左右子树都访问完才记录当前节点
  };
  dfs(root);
  return res;
}

/**
 * 后序遍历（迭代）：先按 根 -> 右 -> 左 收集，最后整体反转得到 左 -> 右 -> 根。
 * @param {TreeNode|null} root 二叉树根节点
 * @returns {number[]} 后序遍历得到的节点值
 */
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
  // 例如示例树先得到 3,20,7,15,9，反转后为 9,15,7,20,3。
  return res.reverse();
}

/**
 * 层序遍历：用数组当队列，逐层收集结果。
 * @param {TreeNode|null} root 二叉树根节点
 * @returns {number[][]} 每层的节点值，按从上到下、从左到右排列
 */
function levelOrder(root) {
  const res = [];
  if (root === null) {
    return res;
  }

  let queue = [root]; // 当前层的所有节点
  while (queue.length > 0) {
    const level = []; // 当前层的节点值
    const next = []; // 下一层的节点

    // 遍历当前层，同时把孩子们收集到 next。
    for (const node of queue) {
      level.push(node.val);
      if (node.left !== null) {
        next.push(node.left);
      }
      if (node.right !== null) {
        next.push(node.right);
      }
    }

    // 一层处理完就记录结果，再换到下一层。
    // 这里用 next 整体替换 queue，避免从队头 shift（shift 是 O(n)）。
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

// 前序：3, 9, 20, 15, 7
console.log('前序遍历（递归）:', preorderTraversal(root));
console.log('前序遍历（迭代）:', preorderTraversalIterative(root));
// 中序：9, 3, 15, 20, 7
console.log('中序遍历（递归）:', inorderTraversal(root));
console.log('中序遍历（迭代）:', inorderTraversalIterative(root));
// 后序：9, 15, 7, 20, 3
console.log('后序遍历（递归）:', postorderTraversal(root));
console.log('后序遍历（迭代）:', postorderTraversalIterative(root));
// 层序：[[3], [9, 20], [15, 7]]
console.log('层序遍历:', levelOrder(root));
