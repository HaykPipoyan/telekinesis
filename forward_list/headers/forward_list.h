#ifndef FORWARD_H
#define FORWARD_H

template <typename T>
class forward_List {
public:
    using value_type = T;
    using size_type = size_t;
    using referance = value_type&;
    using const_referance = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;

public:
	forward_list();
	forward_list()
	~forward_list();
	

private:
	struct node {
		value_type data;
		node* next;
		node(const value_type& val) 
			: data{val}
			, next{nullptr}
		{} 
	};
	node* head;	
}


#endif // FORWARD_H
