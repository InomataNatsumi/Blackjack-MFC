
// Blackjack MFCDlg.h : ヘッダー ファイル
//

#pragma once

#define WM_CUSTOM_DISABLE_BUTTON (WM_USER + 1)


// CBlackjackMFCDlg ダイアログ
class CBlackjackMFCDlg : public CDialogEx
{

// コンストラクション

public:

	CBlackjackMFCDlg(CWnd* pParent = nullptr);	// 標準コンストラクター

	int card[52];
	int yS; //あなたの合計
	int yC = 4; //あなたが引くカード
	int dS = 0; //ディーラーの合計
	int dC = 2; //ディーラーが引くカード

	CString kaishi; //メインのテキスト宣言

	CString YcardText; //あなたの引いたカードのテキスト宣言

	CString yScore; //あなたのスコアのテキスト宣言

	CString DcardText; //ディーラーの引いたカードのテキスト宣言

	CString YcardM;

	CString YcardN;


	bool flag = true;
	bool flag2 = true;
    int flag3 = 0;
	int flag4 = 0;


	CWnd* kaishiText; //メインのテキスト IDC_STATIC2

	CWnd* DCard; //ディーラーの引いたカード IDC_STATIC3

	CWnd* YCard; //あなたの引いたカード IDC_STATIC4

	CWnd* YScore; //あなたのスコア IDC_STATIC5

	CWnd* judgeText; //勝敗のテキスト IDC_STATIC6



// ダイアログ データ

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BLACKJACK_MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装

protected:

	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedKaishi();
	afx_msg void OnBnClickedSyuryou();
	afx_msg void OnBnClickedHit();
	afx_msg void OnBnClickedStand();
	afx_msg void Dealer();
	afx_msg void Dealer2();
	afx_msg void Judge();
	afx_msg void Reset();
	afx_msg void End();
	afx_msg UINT GetClickedButtonID();
};
