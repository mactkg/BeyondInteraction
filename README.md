BeyondInteraction
=================

書籍「[Beyond Interaction - メディアアートのためのopenFrameworksプログラミング入門](http://www.bnn.co.jp/books/title_index/web/beyond_interaction_openframewo.html)」のソースコード配布のためのリポジトリです。

書籍のPDFデータは、Creaticve Commonsライセンス(CC-BY-NC-SA)で配布しています。

* [Beyond Interaction – PDF edition（8.8 MB）](http://www.bnn.co.jp/download/beyond_interaction/BNN_BeyondInteraction.pdf)

全てのプロジェクトは、openFrameworks v0073でビルドできるように作成しました。openFrameworksのフレームワーク本体は、下記からダウンロードしてください。

* [openFrameworks > download](http://www.openframeworks.cc/download/)


追記
====

当時とはもう色々変わっていて、例えばofxBox2dなんかはアドオンすら落とせません。GitHubの[このリポジトリ](https://github.com/vanderlin/ofxBox2d)に移りました。中のプログラムもそれなりに変更を加えなくてはいけなくて、初学者がちゃんと理解していけるかというと微妙なところです。とりあえず動くようにしておいたので、気になる人は見てください。

GitHubからアドオンのデータを落としてくるには、``svn...``のコマンドの代わりに、以下のコマンドを打ち込むと良いです。

```
git clone https://github.com/vanderlin/ofxBox2d.git
```

もしくは、[ここ](https://github.com/vanderlin/ofxBox2d/archive/master.zip)からダウンロードできます。


ちょっとした解説
================

おもに行っている変更は、２つです。ひとつは[最新版のofxBox2dをプログラムに組み込むようにする変更](https://github.com/mactkg/BeyondInteraction/commit/ab4294c2d53217b6b58750e88048c697e7f0af85)(多分これは見てもわけわかんないです)で、もうひとつは[最新版のofxBox2dに対応したプログラムにするための変更](https://github.com/mactkg/BeyondInteraction/commit/62b805de59533c5bb7a3e1b0d3fccad40d4bf42b)です。

ofxBox2dをプログラムに組み込むようにする作業
======================================
======================================

基本的にはBeyond Interactionに書いてあったように行います。アドオンを持ってくるだけです。ただ、それだけではだめで、"Header Search Paths"という設定にアドオンのヘッダファイルのありかを教えなくてはならない時があります。この作業は、次のようにできます。たいてい、"../../../addons/{アドオン名}/libs"とかでOKです。それはアドオンのフォルダ構造を見ながらやります。

![http://gyazo.com/7ffe71bcae98a97e44b8b2e7d25fca46](http://i.gyazo.com/7ffe71bcae98a97e44b8b2e7d25fca46.gif)

最新版のofxBox2dに対応したプログラムにする変更
========================================
========================================

これはオブジェクトをofPtrというオブジェクトでくるんであげれば良いです。例えば

```cpp
vector <ofxBox2dCircle> circles;
ofxBox2dCircle circle;
circles.push_back(circle);
```

というコードが書いてあったとしたら、

```cpp
vector <ofPtr<ofxBox2dCircle> > circles;
ofPtr<ofxBox2dCircle> circle = ofPtr<ofxBox2dCircle>(new ofxBox2dCircle);
circles.push_back(circle);
```

となります。

オブジェクトへアクセスする方法も少し違います。

```cpp
circles[0].setup(); // 0番目にアクセス
```

***ではなく***

```cpp
circlesp[0].get()->setup(); // 0番目にアクセス
```

となります。大体この辺りだけ気をつければ良いかもしれません。あんまり触ったこと無いので分からないんですが、多分大丈夫。。。