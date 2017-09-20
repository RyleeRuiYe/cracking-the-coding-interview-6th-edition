/*
 * WordFrequencies ��һ������ĳ���ʵĳ��ִ�����������������
 * ˼·��
 * When someone create some thing with all of their hearts, 
 * then that creature is given a soul
 */


/* һ�� ���ʱ�������ָ�����ʳ���ʱ����������1��
 * ʱ�俪��O(n)�����������Ż�����Ϊ�����������ÿһ������
 */
int getFrequency(String[] book, String word)
{
	word = word.trim().toLowerCase();
	int count = 0;
	for (String w : book)
	{
		if (w.trim().toLowerCase.equals(word))
			count++;
	}
	return count;
}

/*
  �����е�����Ԥ����ʹ��hash��ѵ���ӳ�䵽��Ƶ
  ʱ�俪��O(1)
*/
HashMap<String, Integer> setupDictionary(String[] book)
{
	HashMap<String, Integer> table = new HashMap<String, Integer>();
	for (String word : book)
	{
		word = word.toLowerCase();
		if (word.trim() != "")
		{
			table.put(word, 0);
		}
		table.put(word, table.get(word) + 1);
	}
	return table;
}

int getFrequency(HashMap<String, Integer> table, String word)
{
	if (table == NULL || word == NULL)
		return -1;
	word = word.toLowerCase();
	if (table.containsKey(word))
		return table.get(word);
	return 0;
}
