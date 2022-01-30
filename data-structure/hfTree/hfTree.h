#ifndef HFTREE_H
#define HFTREE_H
template <class Type>
class hfTree
{
private:
	struct Node    //数组中的元素类型
	{
		Type data;    //结点值
		int weight;    //结点的权值
		int parent, left, right;    //父结点及左右儿子的下标地址
	};

	Node* elem;
	int length;

public:
	struct hfCode    //保存哈夫曼编码的类型
	{
		Type data;    //待编码的字符
		string code;    //对应的哈夫曼编码
	};

	hfTree(const Type* v, const int* w, int size);
	void getCode(hfCode result[]);    //从哈夫曼树生成哈夫曼编码
	~hfTree() { delete[]elem; };
};
#endif // !HFTREE_H
