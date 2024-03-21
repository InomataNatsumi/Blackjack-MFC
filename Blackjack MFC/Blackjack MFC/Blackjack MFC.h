
// Blackjack MFC.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CBlackjackMFCApp:
// このクラスの実装については、Blackjack MFC.cpp を参照してください
//

class CBlackjackMFCApp : public CWinApp
{
public:
	CBlackjackMFCApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CBlackjackMFCApp theApp;
