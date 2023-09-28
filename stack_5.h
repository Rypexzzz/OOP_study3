template <typename type>
class node
{
	template <typename type> friend class stack;
private:
	type pole;
	node* next;
public:
	node():pole(0){
		next = NULL;
	}
	node(type pol_inp) :pole(pol_inp) {
		next = NULL;
	}
	node(node& node_inp) :pole(node_inp.pole), next(node_inp.next) {}
	~node() {
		if (next != nullptr) delete next;
	}
};

template <typename type>
class stack {
private:
	node<type>* up;
public:
	stack() {
		up = nullptr;
	}
	stack(node<type>* up_inp):up(up_inp){}
	stack(stack& stack_copy):up(stack_copy.up){}
	~stack(){
		while (up != nullptr) {
			node<type>* next = up->next;
			delete up;
			up = next;
		}
	}
	void inject(type inp) {
		node<type>* now = new node<type>(inp);
		now->next = up;
		up = now;
	}

	type extract() {
		if (up == nullptr) throw 1;
		type ret = up->pole;
		up = up->next;
		return ret;

	}

	void show() {
		node<type>* cur=up;
		while (cur != nullptr) {
			std::cout << cur->pole << " ";
			cur = cur->next;
		}
		std::cout << std::endl;
	}
};

