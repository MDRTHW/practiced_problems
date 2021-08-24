#include <iostream>
#include <deque>
using namespace std;
int main(){
	int n, k, i, t, l, h, j;
	deque<int> arr, ark;
	deque<deque<int>> m;
	cout << "Enter the length: ";
	cin >> n;
	cout << "Enter the sequence: ";
	for(i = 0; i < n; i++){
		cin >> k;
		arr.push_back(k);}
	for(i = 0; i < n; i++){
		ark.clear();
		ark.push_back(arr[i]);
		t = i;
		for(j = i + 1; j < n; j++){
			if(arr[j] > arr[t]){
				ark.push_back(arr[j]);
				t = j;}}
		m.push_back(ark);}
	l = h = 0;
	for(i = 0; i < (int)m.size(); i++){
		if((int)m[i].size() > l){
			l = (int)m[i].size();
			h = i;}}
	for(int y : m[h]){
		cout << y << " ";}
	cout << endl;
	
	m.clear();
	for(i = 0; i < n; i++){
		ark.clear();
		ark.push_back(arr[i]);
		t = i;
		for(j = i + 1; j < n; j++){
			if(arr[j] < arr[t]){
				ark.push_back(arr[j]);
				t = j;}}
		m.push_back(ark);}
	l = h = 0;
	for(i = 0; i < (int)m.size(); i++){
		if((int)m[i].size() > l){
			l = (int)m[i].size();
			h = i;}}
	for(int y : m[h]){
		cout << y << " ";}
	return 0;}
