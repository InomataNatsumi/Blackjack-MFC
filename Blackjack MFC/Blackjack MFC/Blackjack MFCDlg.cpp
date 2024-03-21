
// Blackjack MFCDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "Blackjack MFC.h"
#include "Blackjack MFCDlg.h"
#include "afxdialogex.h"
#include "Blackjack.h"

#ifdef _DEBUG
#define new DEBUG_NEW //_DEBUG マクロが定義されている場合、new 演算子が DEBUG_NEW マクロに置き換えられます。DEBUG_NEW マクロは、メモリの割り当て時にデバッグ情報を追加するためのものであり、メモリリークの原因を特定するのに役立ちます。
#endif
//メモリリークは、プログラムが動作中にメモリを動的に割り当てたにもかかわらず、それを解放しない状態を指します。



// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx //CAboutDlg クラスが CDialogEx クラスを継承していることを示しています。CDialogEx クラスは、MFCフレームワークでダイアログ ボックスの作成に使用されるクラスです。
{
public:
	CAboutDlg(); //CAboutDlg クラスのパブリックなコンストラクタ CAboutDlg() を宣言しています。このコンストラクタは、ダイアログの作成時に呼び出されます。

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX }; //AFX_DESIGN_TIME が定義されている場合、IDD_ABOUTBOX という識別子を持つダイアログリソースの ID を IDD として定義します。
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX); //MFC のデータ交換とバリデーション(DDX / DDV) サポートを提供します。通常、ダイアログ上のコントロールとクラスのメンバー変数との間でデータを交換するために使用されます。
// 実装
protected:
	DECLARE_MESSAGE_MAP() //DECLARE_MESSAGE_MAP() マクロを使用してメッセージ マップを宣言しています。メッセージ マップは、MFC でメッセージを処理するための機構であり、イベントやユーザーアクションに応答するためのハンドラー関数を関連付けます。
};


CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX) //CAboutDlg クラスのコンストラクタの定義です。コロンの後にある CDialogEx(IDD_ABOUTBOX) の部分は、CAboutDlg クラスの親クラスである CDialogEx のコンストラクタを呼び出しています。引数として IDD_ABOUTBOX を渡しています。これは、このダイアログのリソース ID を指定しています。
{
}



void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);//この関数は、ダイアログボックス上のコントロールと対応するクラスメンバー変数を交換するためのデータ交換処理を実行します。MFC ダイアログアプリケーションでは、ダイアログボックスのコントロールと関連する変数を相互に更新するために使用されます。
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx) //マクロが開始されます。これは、メッセージハンドラー関数とメッセージIDをマッピングするためのものです。
END_MESSAGE_MAP()





// CBlackjackMFCDlg ダイアログ

CBlackjackMFCDlg::CBlackjackMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BLACKJACK_MFC_DIALOG, pParent),
	  yS(0),
	  yC(4),
	  kaishiText(nullptr), // kaishiText を nullptr で初期化
	  DCard(nullptr),
	  YCard(nullptr),
	  YScore(nullptr),
	  judgeText(nullptr)

	//CBlackjackMFCDlg クラスのコンストラクタを定義しています。このコンストラクタは、親クラスである CDialogEx のコンストラクタを呼び出しています。CDialogEx クラスのコンストラクタは、ダイアログのリソース ID (IDD_BLACKJACK_MFC_DIALOG) を指定してダイアログを作成します。また、pParent ポインタをオプションで受け取りますが、デフォルトでは nullptr が指定されています。これにより、親ウィンドウを持たないダイアログが作成されます。
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME); //m_hIcon メンバー変数に、リソース ID (IDR_MAINFRAME) で指定されたアイコンをロードする操作を行っています。AfxGetApp() 関数は、アプリケーションのポインタを取得し、その LoadIcon() メソッドは、指定されたアイコンのリソースを読み込みます。このアイコンは、通常、アプリケーションのメインフレームウィンドウのアイコンとして使用されます。

	// card 配列の初期化 {}に1～52入れる
	for (int i = 0; i < 52; i++) {
		card[i] = i + 1;
	}
}



void CBlackjackMFCDlg::DoDataExchange(CDataExchange* pDX) //この関数は、ダイアログボックス上のコントロールと対応するクラスメンバー変数を交換するためのデータ交換処理を実行します。MFC ダイアログアプリケーションでは、ダイアログボックスのコントロールと関連する変数を相互に更新するために使用されます。
{
	CDialogEx::DoDataExchange(pDX);
}



BEGIN_MESSAGE_MAP(CBlackjackMFCDlg, CDialogEx) //BEGIN_MESSAGE_MAPマクロは、特定のクラス（ここではCBlackjackMFCDlg）に関連付けられたメッセージハンドラー関数と、それに対応するメッセージIDのマッピングを開始します。

	//ウィンドウメッセージ（WM）を処理するためのメンバー関数を指定します。
	ON_WM_SYSCOMMAND() //システムコマンドが発生した際に呼び出される関数 OnSysCommand
	ON_WM_PAINT() //ウィンドウの描画が必要な際に呼び出される関数 OnPaint
	ON_WM_QUERYDRAGICON() //ドラッグされているアイコンを取得する際に呼び出される関数 OnQueryDragIcon

	//ON_BN_CLICKEDはボタンがクリックされたときに呼び出されるメンバー関数を指定します。

	/*ON_BN_CLICKED(IDOK, &CBlackjackMFCDlg::OnBnClickedKaishi) *///「OK」ボタンがクリックされたときに OnBnClickedKaishi 関数を呼び出します。

	ON_BN_CLICKED(IDC_BUTTON5, &CBlackjackMFCDlg::OnBnClickedKaishi) //IDC_BUTTON5 というボタンがクリックされたときに CBlackjackMFCDlg クラスの OnBnClickedKaishi 関数が呼び出されます。

	ON_BN_CLICKED(IDC_BUTTON6, &CBlackjackMFCDlg::OnBnClickedSyuryou)

	ON_BN_CLICKED(IDC_BUTTON3, &CBlackjackMFCDlg::OnBnClickedHit)

	ON_BN_CLICKED(IDC_BUTTON4, &CBlackjackMFCDlg::OnBnClickedStand)

END_MESSAGE_MAP() //END_MESSAGE_MAPマクロは、マップの終了を示します。




// CBlackjackMFCDlg メッセージ ハンドラー

BOOL CBlackjackMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog(); //CDialogEx クラスの OnInitDialog 関数を呼び出しています。

	// テキストを中央に表示するためのスタイルを追加
	CWnd* pStaticText = GetDlgItem(IDC_STATIC2);
	if (pStaticText)
	{
		pStaticText->ModifyStyle(0, SS_CENTER); // SS_CENTER スタイルを追加
	}

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX); //IDM_ABOUTBOX という識別子が正しい範囲内にあることを確認しています。IDM_ABOUTBOX はメニュー項目の識別子であり、0xFFF0 との論理積をとって自身と一致するかどうかを確認しています。
	ASSERT(IDM_ABOUTBOX < 0xF000); //DM_ABOUTBOX が 0xF000 よりも小さい値であることを確認しています。IDM_ABOUTBOX はメニュー項目の識別子であり、0xF000 はシステムメニューの範囲外の識別子です。したがって、IDM_ABOUTBOX はシステムメニューの範囲内である必要があります。

	CMenu* pSysMenu = GetSystemMenu(FALSE); //GetSystemMenu 関数は、ウィンドウのシステムメニューへのポインターを返します。引数 FALSE は、この関数がウィンドウのシステムメニューを取得することを指示します。
	if (pSysMenu != nullptr) //システムメニューが正常に取得された場合、ポインター pSysMenu は nullptr ではなく、有効なアドレスを保持します。条件文は、このポインターが nullptr でないことを確認しています。
	{
		BOOL bNameValid; //変数 bNameValid を宣言
		CString strAboutMenu; //CString 型の変数 strAboutMenu を宣言
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX); //リソースID IDS_ABOUTBOX に対応する文字列をリソースから読み込み、strAboutMenu 変数にその文字列を格納しています。また、LoadString 関数の戻り値を bNameValid 変数に代入しています。
		ASSERT(bNameValid); //bNameValid 変数が真であることをアサートしています。つまり、LoadString 関数が成功し、strAboutMenu に有効な文字列がロードされたことを確認しています。
        //アサート（assertion）は、プログラム内で特定の条件が満たされているかどうかを検証するためのテスト文です。

		if (!strAboutMenu.IsEmpty()) //strAboutMenuが空でない場合に条件が成立します。
		{
			pSysMenu->AppendMenu(MF_SEPARATOR); //システムメニューに区切り線を追加しています。MF_SEPARATORは、メニューアイテムが区切り線であることを指定します。
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu); //システムメニューに新しいメニューアイテムを追加しています。MF_STRINGは、メニューアイテムが文字列であることを指定し、IDM_ABOUTBOXはそのアイテムの識別子、strAboutMenuは表示される文字列です。
		}
	}

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定


	// TODO: 初期化をここに追加します。

	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE); // ボタンを無効にする
	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE); // ボタンを無効にする

	kaishiText = GetDlgItem(IDC_STATIC2); //メインのテキスト // IDC_STATIC2は静的テキストのID
	DCard = GetDlgItem(IDC_STATIC3); //ディーラーの引いたカード
	YCard = GetDlgItem(IDC_STATIC4); //あなたの引いたカード
	YScore = GetDlgItem(IDC_STATIC5); //あなたのスコア
	judgeText = GetDlgItem(IDC_STATIC6); //勝敗のテキスト

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}



void CBlackjackMFCDlg::OnSysCommand(UINT nID, LPARAM lParam) //この関数では、システムコマンドの識別子（nID）とその追加情報（lParam）が渡されます。
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX) //IDM_ABOUTBOX は通常、アプリケーションのバージョン情報などを表示するためのダイアログボックスを開くためのシステムコマンドを示します。この条件式は、送られてきたシステムコマンドが「情報ボックスに関するもの」であるかどうかを確認するために使用されます。
	{
		CAboutDlg dlgAbout; //CAboutDlg クラスのオブジェクトである dlgAbout を宣言
		dlgAbout.DoModal(); //dlgAbout オブジェクトの DoModal() メソッドを呼び出しています。
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam); //CDialogEx クラスの OnSysCommand 関数を呼び出しています。
	}
}



// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CBlackjackMFCDlg::OnPaint() //ウィンドウが再描画される際に呼び出されます。
{
	if (IsIconic()) //ウィンドウが最小化されているかどうかを確認しています。
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト
		//CPaintDC オブジェクト dc は、ウィンドウのクライアント領域を描画するためのデバイス コンテキストを表します。このデバイス コンテキストは、描画操作を行うために使用されます。this ポインタを渡すことで、ウィンドウのクライアント領域を描画対象として指定しています。

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0); //ウィンドウのアイコンが描画される背景を消去するために WM_ICONERASEBKGND メッセージを送信しています。dc.GetSafeHdc() は、デバイス コンテキストのハンドルを取得しています。reinterpret_cast<WPARAM>(dc.GetSafeHdc()) は、デバイス コンテキストのハンドルを WPARAM 型にキャストしています。

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON); //システム メトリックスからアイコンの横幅（ピクセル単位）を取得しています。SM_CXICON は、アイコンの横幅を取得するためのシステム定数です。
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect; //CRect オブジェクト rect を宣言しています。CRect は、MFC で矩形を表すためのクラスです。
		GetClientRect(&rect); //ウィンドウのクライアント領域の座標を取得し、rect 変数にその情報を格納しています。GetClientRect 関数は、ウィンドウのクライアント領域の座標を取得するために使用されます。
		int x = (rect.Width() - cxIcon + 1) / 2; //ウィンドウのクライアント領域の中央にアイコンを描画するための x 座標を計算しています。具体的には、ウィンドウの幅からアイコンの幅を引き、その結果を2で割り、その後1を加えています。
		int y = (rect.Height() - cyIcon + 1) / 2; //ウィンドウのクライアント領域の中央にアイコンを描画するための y 座標を計算しています。具体的には、ウィンドウの高さからアイコンの高さを引き、その結果を2で割り、その後1を加えています。

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon); //指定された座標 (x, y) にアイコンを描画するための DrawIcon 関数を呼び出しています。
	}
	else
	{
		CDialogEx::OnPaint(); //親クラスの OnPaint 関数が呼び出され、ダイアログの標準的な描画処理が行われます。
	}
}



// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CBlackjackMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon); //ウィンドウがドラッグされているときに表示されるカーソルのハンドルを返すためのものです。ウィンドウのアイコンをカーソルとして使用するために、m_hIcon を HCURSOR 型にキャストして返しています。
}
//ハンドルとは、プログラム内のリソースやオブジェクトに対する識別子や参照を示す特殊な値です。通常、ハンドルはメモリアドレスではなく、プログラムがオブジェクトを一意に識別するための抽象化された値です。
//ウィンドウがドラッグされているときとは、ユーザーがウィンドウのタイトルバーをクリックし、マウスを押し続けた状態で移動させているときのことを指します。この操作により、ウィンドウ全体がマウスの移動に従って移動します。




void CBlackjackMFCDlg::OnBnClickedKaishi() //IDC_BUTTON5
{

	int i;
	int a; //空き
	int num;

	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE); // ヒットボタンを有効にする
	GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE); // スタンドボタンを有効にする
	GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE); // 開始ボタンを無効にする
	UpdateWindow(); // ウィンドウ全体の再描画をトリガーする

		// テキストを変更する
		kaishiText->SetWindowText(_T("☆★☆★☆★☆★☆★ブラックジャックへようこそ！☆★☆★☆★☆★☆★")); //SetWindowText関数は、ウィンドウやコントロールのテキストを変更するために使用されます。

		// 短い待機時間を挿入する
		Sleep(1000); // 1000ミリ秒（1秒）待機

		kaishiText->SetWindowText(_T("ゲームを開始します。"));

		Sleep(1000); // 待機

		kaishiText->SetWindowText(_T("あなたがカードを2枚引きました。"));

		Sleep(1000); // 待機
		

		//シャッフルする
		srand((unsigned int)time(NULL));
		for (i = 0; i < 52; i++) {
			num = rand() % 52;

			a = card[i];
			card[i] = card[num];
			card[num] = a;
		}


		//あなたの引いた1・2枚目のカード

		CString YcardText; //あなたの引いたカードのテキスト宣言

		CString yScore; //あなたのスコアのテキスト宣言


		CString YcardM(Card::cM(card[0]).c_str()); // std::string を CString に変換
		CString YcardN(Card::cN(card[0]));

		YcardText.Format(_T("%s%s"), static_cast<LPCTSTR>(YcardM), static_cast<LPCTSTR>(YcardN)); //Format メソッドは、文字列を指定されたフォーマットに従って整形するために使用されます。
		//static_cast<LPCTSTR>は、変数cardMをLPCTSTR型に変換します。LPCTSTRは、関数の引数やWindows APIなどで文字列を渡す際に使用されます。
		YCard->SetWindowText(YcardText);


		if (Score::A(card[0])) { // Score::Aが true の場合

			flag3 = 1;
			flag4 = 1;

			kaishiText->SetWindowText(_T("1点を選ぶ場合はヒット、11点を選ぶ場合はスタンドをクリックしてください。"));

			GetClickedButtonID();

		}

		else {

			yS = Score::YcP(card[0]);
			yScore.Format(_T("%d"), yS);
			YScore->SetWindowText(yScore);
		}

		Sleep(1000); // 待機

		YcardM = (Card::cM(card[1]).c_str()); // std::string を CString に変換
		YcardN = (Card::cN(card[1]));

		YcardText.AppendFormat(_T(" %s%s"), static_cast<LPCTSTR>(YcardM), static_cast<LPCTSTR>(YcardN)); //Append メソッドは、文字列を追加(上書き)します。
		YCard->SetWindowText(YcardText);

		if (Score::A(card[1])) { // Score::Aが true の場合

			flag3 = 2;
			flag4 = 2;

			kaishiText->SetWindowText(_T("1点を選ぶ場合はヒット、11点を選ぶ場合はスタンドをクリックしてください。"));

			GetClickedButtonID();

		}

		else {

			yS = yS + Score::YcP(card[1]);
			yScore.Format(_T("%d"), yS);
			YScore->SetWindowText(yScore);

			Dealer();
		}
}


void CBlackjackMFCDlg::OnBnClickedSyuryou() //IDC_BUTTON6
{
	PostQuitMessage(0); //現在のアプリケーションのメッセージキューに終了メッセージを投稿するためのWinAPI関数です。通常、0を渡すと正常終了を意味しますが、他の値を渡すこともできます。
}



void CBlackjackMFCDlg::OnBnClickedHit() //IDC_BUTTON3
{


		if (flag3 == 1) { // card[0] がAの場合

				kaishiText->SetWindowText(_T("1点を選びました。"));

				yS = 1;

				yScore.Format(_T("%d"), yS); // スコアの文字列を更新
				YScore->SetWindowText(yScore); // スコアを表示

				flag3 = 0;
				flag4 = 0;

				Sleep(1000); // 待機

				YcardM = (Card::cM(card[1]).c_str()); // std::string を CString に変換
				YcardN = (Card::cN(card[1]));

				YCard->GetWindowText(YcardText); // 既存のカード表示を取得
				YcardText.AppendFormat(_T(" %s%s"), static_cast<LPCTSTR>(YcardM), static_cast<LPCTSTR>(YcardN)); //Append メソッドは、文字列を追加(上書き)します。
				YCard->SetWindowText(YcardText);

				if (Score::A(card[1])) { // Score::Aが true の場合

					flag3 = 2;
					flag4 = 2;

					kaishiText->SetWindowText(_T("1点を選ぶ場合はヒット、11点を選ぶ場合はスタンドをクリックしてください。"));

					GetClickedButtonID();

				}

				else {

					yS = yS + Score::YcP(card[1]);
					yScore.Format(_T("%d"), yS);
					YScore->SetWindowText(yScore);

					if (yS == 21) {

						kaishiText->SetWindowText(_T("ナチュラルブラックジャック！"));

						Sleep(1000); // 待機

						judgeText->SetWindowText(_T("User WIN！"));

						End();
					}

					else {

						Dealer();
					}
				}
		}

		else if (flag3 == 2) { // card[1] がAの場合

			kaishiText->SetWindowText(_T("1点を選びました。"));

			yS = yS + 1;

			yScore.Format(_T("%d"), yS); // スコアの文字列を更新
			YScore->SetWindowText(yScore); // スコアを表示

			flag3 = 0;
			flag4 = 0;

			if (yS == 21) {

				kaishiText->SetWindowText(_T("ナチュラルブラックジャック！"));

				Sleep(1000); // 待機

				judgeText->SetWindowText(_T("User WIN！"));

				End();
			}

			else {

				Dealer();
			}
		}

		else if (flag3 == 0) { // それ以外の場合

			CString YcardM(Card::cM(card[yC]).c_str()); // スートの文字列を取得
			CString YcardN(Card::cN(card[yC])); // 数字の文字列を取得

			if (Score::A(card[yC])) { // Score::Aが true の場合

				if (flag) { // flag が true の場合

					flag = false;
					flag2 = false;

					kaishiText->SetWindowText(_T("あなたがカードを1枚引きました。"));

					YCard->GetWindowText(YcardText); // 既存のカード表示を取得
					YcardText.AppendFormat(_T(" %s%s"), static_cast<LPCTSTR>(YcardM), static_cast<LPCTSTR>(YcardN)); // 新しいカードを追加
					YCard->SetWindowText(YcardText);

					Sleep(1000); // 待機

					kaishiText->SetWindowText(_T("1点を選ぶ場合はヒット、11点を選ぶ場合はスタンドをクリックしてください。"));

				}

				else { // flag が false の場合

					kaishiText->SetWindowText(_T("1点を選びました。"));

					yS = yS + 1;

					yScore.Format(_T("%d"), yS); // スコアの文字列を更新
					YScore->SetWindowText(yScore); // スコアを表示

					yC++;

					Sleep(1000); // 待機

					Judge();

					flag = true;
					flag2 = true;
				}
			}

			else { //ヒットする場合

				kaishiText->SetWindowText(_T("あなたがカードを1枚引きました。"));

				YCard->GetWindowText(YcardText); // 既存のカード表示を取得
				YcardText.AppendFormat(_T(" %s%s"), static_cast<LPCTSTR>(YcardM), static_cast<LPCTSTR>(YcardN)); // 新しいカードを追加
				YCard->SetWindowText(YcardText);

				yS = yS + Score::YcP(card[yC]); // スコアを更新
				yScore.Format(_T("%d"), yS); // スコアの文字列を更新
				YScore->SetWindowText(yScore); // スコアを表示

				yC++;

				Sleep(1000); // 待機

				Judge();

			}
		}
		GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE); // ヒットボタンを有効にする
		GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
}



void CBlackjackMFCDlg::OnBnClickedStand() //IDC_BUTTON4
{

	if (flag4 == 1) { // card[0] がAの場合

		kaishiText->SetWindowText(_T("11点を選びました。"));

		yS = 11;

		yScore.Format(_T("%d"), yS); // スコアの文字列を更新
		YScore->SetWindowText(yScore); // スコアを表示

		flag3 = 0;
		flag4 = 0;

		if (yS == 21) {

			kaishiText->SetWindowText(_T("ナチュラルブラックジャック！"));

			Sleep(1000); // 待機

			judgeText->SetWindowText(_T("User WIN！"));

			End();
		}

		Sleep(1000); // 待機

		YcardM = (Card::cM(card[1]).c_str()); // std::string を CString に変換
		YcardN = (Card::cN(card[1]));

		YCard->GetWindowText(YcardText); // 既存のカード表示を取得
		YcardText.AppendFormat(_T(" %s%s"), static_cast<LPCTSTR>(YcardM), static_cast<LPCTSTR>(YcardN)); //Append メソッドは、文字列を追加(上書き)します。
		YCard->SetWindowText(YcardText);

		if (Score::A(card[1])) { // Score::Aが true の場合

			flag3 = 2;
			flag4 = 2;

			kaishiText->SetWindowText(_T("1点を選ぶ場合はヒット、11点を選ぶ場合はスタンドをクリックしてください。"));

			GetClickedButtonID();

		}

		else {

			yS = yS + Score::YcP(card[1]);
			yScore.Format(_T("%d"), yS);
			YScore->SetWindowText(yScore);

			if (yS == 21) {

				kaishiText->SetWindowText(_T("ナチュラルブラックジャック！"));

				Sleep(1000); // 待機

				judgeText->SetWindowText(_T("User WIN！"));

				End();
			}

			else {

				Dealer();

			}
		}
	}

	else if (flag4 == 2) { // card[1] がAの場合

		kaishiText->SetWindowText(_T("11点を選びました。"));

		yS = yS + 11;

		yScore.Format(_T("%d"), yS); // スコアの文字列を更新
		YScore->SetWindowText(yScore); // スコアを表示

		flag3 = 0;
		flag4 = 0;

		if (yS == 21) {

			kaishiText->SetWindowText(_T("ナチュラルブラックジャック！"));

			Sleep(1000); // 待機

			judgeText->SetWindowText(_T("User WIN！"));

			End();
		}

		else {

			Dealer();

		}

	}

	else if (flag4 == 0) { // それ以外の場合

		CString YcardM(Card::cM(card[yC]).c_str()); // スートの文字列を取得
		CString YcardN(Card::cN(card[yC])); // 数字の文字列を取得


		if (!flag) { // flag が false の場合

			kaishiText->SetWindowText(_T("11点を選びました。"));

			yS = yS + 11;

			yScore.Format(_T("%d"), yS); // スコアの文字列を更新
			YScore->SetWindowText(yScore); // スコアを表示

			yC++;

			Sleep(1000); // 待機

			Judge();

			flag = true;
			flag2 = true;

		}

		else { // それ以外の場合

			Dealer2();
		}
	}
}


void CBlackjackMFCDlg::Dealer() { //ディーラーの引いた1・2枚目のカード


	Sleep(1000); // 待機

	kaishiText->SetWindowText(_T("ディーラーがカードを2枚引きました。"));

	Sleep(1000); // 待機


	CString DcardText; //ディーラーの引いたカードのテキスト宣言

	CString DcardM(Card::cM(card[2]).c_str()); // std::string を CString に変換

	CString DcardN(Card::cN(card[2]));

	DcardText.AppendFormat(_T("%s%s"), static_cast<LPCTSTR>(DcardM), static_cast<LPCTSTR>(DcardN));
	DCard->SetWindowText(DcardText);

	Sleep(1000); // 待機

	DcardText.Append(_T(" ？"));
	DCard->SetWindowText(DcardText);

	Sleep(1000); // 待機

	kaishiText->SetWindowText(_T("ディーラーの2枚目のカードは分かりません。"));

	Sleep(1000); // 待機

	kaishiText->SetWindowText(_T("カードを引きますか？\n引く場合はヒットを、引かない場合はスタンドをクリックしてください。"));

}


void CBlackjackMFCDlg::Dealer2() {


	int j;

	CString DcardM(Card::cM(card[3]).c_str()); // std::string を CString に変換
	CString DcardN(Card::cN(card[3]));

	DCard->GetWindowText(DcardText); // 既存のテキストを取得

	int hatena = DcardText.Find(_T("？")); // 末尾の文字列を検索 Findは、与えられた文字列内で指定された文字列が最初に現れる位置（インデックス）を見つけます。
	if (hatena >= 0) { //0以上の場合に真となります。
		DcardText = DcardText.Left(hatena); // 末尾の文字列を削除 Leftは、与えられた文字列の先頭から指定された数の文字を抽出して新しい文字列として返します。
	}

	DcardText.AppendFormat(_T("%s%s"), static_cast<LPCTSTR>(DcardM), static_cast<LPCTSTR>(DcardN));
	DCard->SetWindowText(DcardText);

	kaishi.Format(_T("ディーラー2枚目のカードは%s%sでした。"), static_cast<LPCTSTR>(DcardM), static_cast<LPCTSTR>(DcardN));
	kaishiText->SetWindowText(kaishi);

	Sleep(1000); // 待機

	kaishiText->SetWindowText(_T("ディーラーがカードを引きます。"));

	Sleep(1000); // 待機


	//ディーラーが17以上になるまで
	dS = Score::DcP(card[2], dS) + Score::DcP(card[3], dS);

	for (j = yC; j < 52; j++) {

		if (dS <= 17) {

			dS = dS + Score::DcP(card[j], dS);

			CString DcardM(Card::cM(card[j]).c_str()); // std::string を CString に変換
			CString DcardN(Card::cN(card[j]));

			DcardText.AppendFormat(_T(" %s%s"), static_cast<LPCTSTR>(DcardM), static_cast<LPCTSTR>(DcardN));
			DCard->SetWindowText(DcardText);

			Sleep(1000); // 待機
		}

		else {
			break;
		}
	}


	DcardText.Format(_T("ディーラーの得点は%dです。"), dS);
	kaishiText->SetWindowText(DcardText);

	Sleep(1000); // 待機


	if (dS > 21) {
		kaishiText->SetWindowText(_T(""));
		judgeText->SetWindowText(_T("User WIN！"));

		End();
	}

	else {

		//勝負
		if (yS > dS) {
			kaishiText->SetWindowText(_T(""));
			judgeText->SetWindowText(_T("User WIN！"));

			End();
		}

		else if (yS < dS && dS < 22) {
			kaishiText->SetWindowText(_T(""));
			judgeText->SetWindowText(_T("User LOSE..."));

			End();
		}

		else {
			kaishiText->SetWindowText(_T(""));
			judgeText->SetWindowText(_T("DRAW"));

			End();
		}
	}
}



void CBlackjackMFCDlg::Judge() {


	if (yS == 21) {

		kaishiText->SetWindowText(_T("ブラックジャック！"));

		Sleep(1000); // 待機

		judgeText->SetWindowText(_T("User WIN！"));

		End();
	}

	else if (yS > 21) {

		kaishiText->SetWindowText(_T(""));

		judgeText->SetWindowText(_T("User LOSE..."));

		End();

	}

	else {

		kaishiText->SetWindowText(_T("カードを引きますか？\n引く場合はヒットを、引かない場合はスタンドをクリックしてください。"));
	}
}



void CBlackjackMFCDlg::Reset(){


	kaishiText->SetWindowText(_T("BLACK JACK"));

	YCard->SetWindowText(_T("あなたの引いたカード"));

	YScore->SetWindowText(_T("0"));

	DCard->SetWindowText(_T("ディーラーの引いたカード"));

	judgeText->SetWindowText(_T(""));

	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE); // ボタンを無効にする
	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE); // ボタンを無効にする
	GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE); // ボタンを有効にする

}



void CBlackjackMFCDlg::End() {


	Sleep(2000); // 待機

	kaishiText->SetWindowText(_T("ブラックジャック終了！また遊んでね★"));

	Sleep(1000); // 待機

	Reset();
}



UINT CBlackjackMFCDlg::GetClickedButtonID() //Unsigned INTeger（符号なし整数）の略称
{

	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE); // ボタンを有効にする
	GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE); // ボタンを有効にする

	MSG msg; //Windows メッセージを処理するために使用されるメッセージ構造体 MSG

	while (::GetMessage(&msg, NULL, 0, 0)) { //GetMessage 関数は、取得されたメッセージがある場合、真となりループが継続します。&msg に取得されたメッセージが格納されます。

		if (msg.message == WM_COMMAND && (LOWORD(msg.wParam) == IDC_BUTTON3 || LOWORD(msg.wParam) == IDC_BUTTON4)) {
			//msg.message == WM_COMMAND：msg 構造体が表すメッセージが、コマンドメッセージであることを確認しています。
			//(LOWORD(msg.wParam) == IDC_BUTTON3 || LOWORD(msg.wParam) == IDC_BUTTON4)：コマンドメッセージが特定のボタン（IDC_BUTTON3 または IDC_BUTTON4）に関連付けられていることを確認しています。
			// LOWORD(msg.wParam) は、コマンドメッセージの wParam パラメーターの下位ワードを取得します。
			// この下位ワードは、コマンド ID を表します。IDC_BUTTON3 と IDC_BUTTON4 は、それぞれボタンコントロールの識別子です。

			// ボタンがクリックされたらループを抜ける
			break;
		}

		::TranslateMessage(&msg);
		//キーボードメッセージを解釈し、仮想キーを文字メッセージに変換します。具体的には、キーダウンメッセージ（WM_KEYDOWN）およびキーアップメッセージ（WM_KEYUP）が対象です。
		//これにより、アプリケーションは仮想キーの代わりに文字入力を処理できます。ただし、マウスメッセージ（例：クリックや移動）はこの関数の対象外です。
		
		::DispatchMessage(&msg);
		//指定されたメッセージをウィンドウプロシージャに送信します。ウィンドウプロシージャは、各ウィンドウで発生したイベント（メッセージ）を処理する関数です。
	}

	return LOWORD(msg.wParam); // ボタンのIDを返す
	//LOWORD() 関数は、16 ビット整数の下位ワード（下位 16 ビット）を取り出すために使用されます。
	// ボタンの識別子は 16 ビット整数として格納されているため、LOWORD(msg.wParam) はボタンの識別子を取得するために使われます。
}