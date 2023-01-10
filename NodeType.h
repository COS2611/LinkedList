#ifndef NodeType_h
#define NodeType_h

template <class Type>
struct NodeType
{
	Type info;
	NodeType<Type> *link;
	NodeType<Type>() : info(NULL), link(NULL) {}
	NodeType<Type>(Type theVal) : info(theVal), link(NULL) {}
};

#endif /* NodeType_h */
