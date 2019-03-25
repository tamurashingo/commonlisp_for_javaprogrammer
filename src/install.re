= インストール

Common LispはANSIで標準化されていて、
その標準に準拠した実装がいろいろとある。
Javaでいうと、旧Sunによる実装だったり、IBMによる実装だったり、
旧BEAによる実装だったり、するようなものである。
処理系のインストールは普通にダウンロードしてきてインストールするやり方と、
Roswellを使った簡単なインストールのやり方がある。

まずは、Roswellを使ったインストールについて見ていく。


== Roswellを使ったインストール

Roswellとは簡単にCommon Lisp実装をインストールするツールだが、
他にも様々なことができる。

 * Lisp実装のインストール
 * Lisp実装の切り替え
 * Lispの起動
 * スクリプトの起動
 * などなど

ここではインストールのやり方について記載していく。

=== Roswellのインストール

RoswellはWikiによるドキュメントが豊富なので、
そちらを参照すれば簡単にインストールすることができる。

https://github.com/roswell/roswell/wiki/Installation

==== Linux (Ubuntu)

Ubuntuの場合、ソースコードからインストールするのが最も簡単である。

//cmd{
$ @<b>{sudo apt-get -y install git build-essential automake libcurl4-openssl-dev}
$ @<b>{git clone -b release https://github.com/roswell/roswell.git}
$ @<b>{cd roswell}
$ @<b>{sh bootstrap}
$ @<b>{./configure}
$ @<b>{make}
$ @<b>{sudo make install}
$ @<b>{ros setup}
//}

筆者の場合、xxenv系と同様にホームディレクトリ下に作成するのが好みなので、
@<tt>{configure}を以下のようにしている。


//cmd{
$ @<b>{./configure --prefix=$HOME/devtool}
//}

==== macOS

macOSの場合、@<tt>{homebrew}で一発である。

//cmd{
$ @<b>{brew install roswell}
//}

==== Windows

筆者の環境にWindowsがないため手順が確認できていないが、
Wikiにビルドしたファイルへのリンクがある。


=== 処理系のインストール

Roswellのインストールがさくっと終わったら次は処理系をインストールしていく。

==== Steel Bank Common Lisp

Steel Bank Common Lispは通称SBCLと呼ばれている。
なので、Roswellでもsbclと指定する。

//cmd{
$ @<b>{ros install sbcl-bin}
//}

`sbcl-bin`なのはビルド済みのバイナリファイルをインストールしているためである。
これを

//cmd{
$ @<b>{ros install sbcl}
//}

とやると、ソースコードからのビルドとなる。

rbenvでRubyをインストールするとソースコードをビルドするようなものである。


==== Clozure CL

Clozure CLは通称CCLなので、Roswellでもcclと指定する。

//cmd{
$ @<b>{ros install ccl-bin}
//}

=== 処理系のインストール後

処理系のインストール後はどの処理系を使うのかを指定する。


//cmd{
$ @<b>{ros list installed}
Installed implementations:

Installed versions of ccl-bin:
ccl-bin/1.11.5

Installed versions of sbcl-bin:
sbcl-bin/1.5.0

Installed versions of sbcl:
sbcl/1.5.0

$ @<b>{ros use sbcl/1.5.0}
//}


== 手動インストール

手動インストールも合わせて紹介しておく。

=== Steel Bank Common Lisp

SBCLはDownloadページにビルド済みのバイナリファイルへのリンクがある。
このファイルを好きなところに展開し、
その中にある@<tt>{run-sbch.sh}を実行すればSBCLが起動する。

//cmd{
$ @<b>{tar xvjf sbcl-1.5.0-x86-64-linux-binary.tar.bz2}
sbcl-1.5.0-x86-64-linux/output/sbcl.core
...
sbcl-1.5.0-x86-64-linux/obj/sbcl-home/contrib/sb-grovel.fasl
$ @<b>{sbcl-1.5.0-x86-64-linux/run-sbcl.sh}
This is SBCL 1.5.0, an implementation of ANSI Common Lisp.
More information about SBCL is available at <http://www.sbcl.org/>.

SBCL is free software, provided as is, with absolutely no warranty.
It is mostly in the public domain; some portions are provided under
BSD-style licenses.  See the CREDITS and COPYING files in the
distribution for more information.
* @<b>{(let ((x 2)}
  @<b>{      (y 3))}
  @<b>{ (+ x y))}
5
* @<b>{(quit)}
$
//}

//image[download_sbcl][Steel Bank Common LispのWebサイト]{
//}


@<tt>{install.sh}を実行してのインストールも可能である。

//cmd{
$ @<b>{INSTALL_ROOT=$HOME/devtool ./install.sh}
//}

@<tt>{SBCL_HOME}環境変数をセットして起動する。

//cmd{
$ @<b>{SBCL_HOME=$HOME/devtool/lib/sbcl $HOME/devtool/bin/sbcl
This is SBCL 1.5.0, an implementation of ANSI Common Lisp.
More information about SBCL is available at <http://www.sbcl.org/>.

SBCL is free software, provided as is, with absolutely no warranty.
It is mostly in the public domain; some portions are provided under
BSD-style licenses.  See the CREDITS and COPYING files in the
distribution for more information.
*
//}


=== Clozure CL

CCLもDownloadページにビルド済みのバイナリファイルへのリンクがある。
そのファイルを展開するだけでインストールは完了である。

その中にある@<tt>{lx86cl64}を実行すればCCLが起動する。

//cmd{
$ @<b>{tar xvzf ccl-1.11.5-linuxx86.tar.gz}
ccl/
...
ccl/compiler/subprims.lisp
$ @<b>{ccl/lx86cl64}
Clozure Common Lisp Version 1.11.5/v1.11.5  (LinuxX8664)

For more information about CCL, please see http://ccl.clozure.com.

CCL is free software.  It is distributed under the terms of the Apache
Licence, Version 2.0.
? @<b>{(let ((x 2)}
  @<b>{      (y 3))}
  @<b>{  (+ x y))}
5
? @<b>{(quit)}
$
//}

//image[download_ccl][Clozure CLのWebサイト]{
//}


