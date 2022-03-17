class Aula{
	var x: Int = 0
	var y: Int = 0

	fun leNums(){
		var num1: Int = readLine()!!.toInt()
		var num2: Int = readLine()!!.toInt()
		this.x = num1
		this.y = num2
	}

	fun operacoes(n1: Int, n2: Int){
		println("Seu num1 eh: $n1 e seu num2 eh: $n2")
		var soma: Int = n1 + n2
		var sub: Int = n1 - n2
		var div: Int = n1 / n2
		var mult: Int = n1 * n2

		println("A soma entre eles: $soma")
		println("A subtracao entre eles: $sub")
		println("A divisao entre eles: $div")
		println("A multiplicacao entre eles: $mult")
	}

}

fun main(){
	val l1 = Aula()
	println("================CALCULADORA COMPLETA=========================")
	println("Insira os numeros:")

	l1.leNums()
	var flag: Boolean

	if(l1.y == 0){
		println("n existe divisao por 0!!")
		flag = false
		l1.leNums()
		
		if(l1.y !=0){
			l1.operacoes(l1.x,l1.y)
		}
		else{
			while(flag == false){
				println("n existe divisao por 0!!")
				l1.leNums()
				if(l1.y != 0){
					flag = true
					l1.operacoes(l1.x,l1.y)
				}
			}
		}
	}

	else{
		l1.operacoes(l1.x, l1.y)
	}
}