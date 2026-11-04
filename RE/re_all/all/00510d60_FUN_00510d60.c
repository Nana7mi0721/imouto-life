
undefined4 FUN_00510d60(undefined4 param_1)

{
  BOOL BVar1;
  int iVar2;
  undefined4 uVar3;
  tagRECT local_10;
  
  if ((DAT_00a20c10 != 1) && (BVar1 = GetClientRect(DAT_00a20bec,&local_10), BVar1 != 0)) {
    DAT_00a20c30 = (int)(short)param_1;
    DAT_00a20c34 = (int)(short)((uint)param_1 >> 0x10);
    DAT_00a20c38 = DAT_00a20c30 + (local_10.right - local_10.left);
    DAT_00a20c3c = DAT_00a20c34 + (local_10.bottom - local_10.top);
    iVar2 = FUN_005166c0();
    if (iVar2 == -4) {
      uVar3 = FUN_0057ab70();
      FUN_0057b060(0);
      FUN_0057b060(uVar3);
    }
  }
  return 0;
}

