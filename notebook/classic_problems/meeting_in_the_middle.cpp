void complete(int &v, Graph &g, Grap &q){	
	for (int w : neighbors[v]){
		if (q.visited[w]) minDistance = min(q.distance[w] + g.distance[v] + 1, minDistance);
		if (!g.visited[w]){
			g.visited[w] = true;
			g.distance[w] = g.distance[v]+1;
			g.p.push(w);
		}
	}		
}

int meeting_in_the_middle(int &start, int &end){
	Graph g1, g2;
	if (start == end) return 0;
	
	minDistance = INF;
	lastLevel = 0;
	
	g1.visited[start] = true;
	g1.distance[start] = 0;
	g1.p.push(start);
	
	g2.visited[end] = true;
	g2.distance[end] = 0;
	g2.p.push(end);
	
	while (!g2.p.empty() && !g1.p.empty()){
		int s = g1.p.front();
		int t = g2.p.front();
		
		g1.p.pop();
		g2.p.pop();
		
		if (g1.distance[s] != lastLevel && minDistance != INF) return minDistance; // Ya se encontraron en un punto anterior y no hay forma de mejorarlo
		else if (g1.distance[s] != lastLevel) lastLevel++; // Actualizo el nivel que estoy iterando
		complete(s, g1, g2); 
		complete(t, g2, g1);  
	}
	
	return 0;
}