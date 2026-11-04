
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00510ba0(HDC param_1,RECT *param_2,int param_3)

{
  HBRUSH pHVar1;
  int iVar2;
  undefined4 uVar3;
  HWND hWnd;
  tagRECT local_10;
  
  DAT_00a2e474 = 1;
  if (DAT_00a210a4 != 0) {
    DAT_00a2e474 = 1;
    return 0;
  }
  if (((DAT_00a21078 == 0) && (DAT_00a23d24 != 0)) && (DAT_00a24d40 == 0)) {
    if (DAT_00a2107c == 0) {
      FUN_0050e510(param_1);
      return 0;
    }
    DAT_00a2e474 = 1;
    return 0;
  }
  if (((DAT_00a49730 == 0) && (DAT_00a20c00 == 0)) || (param_3 != 0)) {
    if (DAT_00a37ed4 == 1) {
      pHVar1 = CreateSolidBrush((DAT_00a37ee0 << 8 | DAT_00a37edc) << 8 | DAT_00a37ed8);
      if (pHVar1 != (HBRUSH)0x0) {
        FillRect(param_1,param_2,pHVar1);
        DeleteObject(pHVar1);
        goto LAB_00510c7e;
      }
      pHVar1 = GetStockObject(4);
    }
    else {
      pHVar1 = GetStockObject(4);
    }
    FillRect(param_1,param_2,pHVar1);
  }
LAB_00510c7e:
  if ((DAT_00a49730 == 0) && (DAT_00a20c00 == 0)) {
    return 0;
  }
  iVar2 = FUN_005166c0();
  if (iVar2 != -2) {
    return 0;
  }
  uVar3 = FUN_00516750();
  FUN_00516710(0);
  if ((DAT_00a20c10 == 0) || (hWnd = DAT_00a20bf0, DAT_00a20bf0 == (HWND)0x0)) {
    hWnd = DAT_00a20bec;
  }
  GetClientRect(hWnd,&local_10);
  if ((((param_2->left == local_10.left) && (param_2->right == local_10.right)) &&
      (param_2->top == local_10.top)) && (param_2->bottom == local_10.bottom)) {
    FUN_00527180();
    FUN_00516710(uVar3);
    return 0;
  }
  if (DAT_00a21070 == 0) {
    DAT_00a21070 = 1;
  }
  else {
    iVar2 = FUN_00550060(0);
    if (iVar2 - _DAT_00a21074 < 0x41) goto LAB_00510d4d;
    FUN_00527180();
  }
  _DAT_00a21074 = FUN_00550060(0);
LAB_00510d4d:
  FUN_00516710(uVar3);
  return 0;
}

