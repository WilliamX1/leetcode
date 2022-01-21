#ifndef HFTREE_H
#define HFTREE_H
template <class Type>
class hfTree
{
private:
	struct Node    //�����е�Ԫ������
	{
		Type data;    //���ֵ
		int weight;    //����Ȩֵ
		int parent, left, right;    //����㼰���Ҷ��ӵ��±��ַ
	};

	Node* elem;
	int length;

public:
	struct hfCode    //������������������
	{
		Type data;    //��������ַ�
		string code;    //��Ӧ�Ĺ���������
	};

	hfTree(const Type* v, const int* w, int size);
	void getCode(hfCode result[]);    //�ӹ����������ɹ���������
	~hfTree() { delete[]elem; };
};
#endif // !HFTREE_H
