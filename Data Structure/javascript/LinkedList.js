function LinkedList(){
	var length = 0;
	var head = null;
}

// append: 리스트끝에 데이터 삽입
LinkedList.prototype.append = function(data){
	var node = new Node(data);
	var curr; 

	// 리스트가 비어있다면
	if(this.head == null){
		this.head = node;
	}
	else{
		curr = this.head;
		// next가 null이 되는 지점동안
		while(curr.next){
			// curr.next는 새로 추가한 노드를 가리킨다
			curr = curr.next;
		}

		curr.next = node;
	}
	this.length++;
};

// removeAt: 데이터의 위치를 기준으로 삭제
LinkedList.prototype.removeAt = function(pos){
	if(pos > -1 && pos < this.length){
		var curr = this.head;
		var prev, index = 0;
	}
	// 삭제하려는 데이터가 리스트의 첫번째인지?
	if(pos == 0){
		this.head = curr.next;
	}
	else{
		while(index++ < pos){
			prev = curr;
			curr = prev.next;
		}

		prev.next = curr.next;
	}
	this.length--;
	curr.next = null;
	return curr.data;
};

// indexOf: 데이터의 값을 받아 리스트에서 해당 데이터의 인덱스를 반환
LinkedList.prototype.indexOf = function(data){
	var curr = this.head;
	var index = -1;

	while(curr){
		if(curr.data === data){
			return index;
		}
		index++;
		curr = curr.next;
	}

	return -1;
};

// remove: 데이터 값을 기준으로 삭제
LinkedList.prototype.remove = function(data){
	var index = this.indexOf(data);
	return this.removeAt(index);
};

// insert: 임의의 위치에 삽입
LinkedList.prototype.insert = function(pos, data){
	if(pos>=0 && pos<=this.length){
		var node = new Node(data);
		var curr = this.head;
		var prev, index = 0;

		if(pos == 0){
			node.next = curr;
			this.head = node;
		}
		else{
			while(index++ < pos){
				prev = curr;
				curr = curr.next;
			}

			node.next = curr;
			prev.next = node;
		}
		this.length++;

		return true;
	}
	// 범위를 벗어낮다면 false를 리턴하여 리스트에 아무것도 추가되지 않았음을 명시
	return false;
};
