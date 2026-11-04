
void FUN_0050e320(void)

{
  undefined4 uVar1;
  HANDLE pvVar2;
  DWORD DVar3;
  undefined4 *puVar4;
  
  if (DAT_00a37a48 == 0) {
    DAT_00a37a48 = 1;
    puVar4 = &DAT_00a2fa4c;
    do {
      pvVar2 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
      *puVar4 = pvVar2;
      puVar4 = puVar4 + 2;
    } while ((int)puVar4 < 0xa37a4c);
    FUN_0056da30(&DAT_00a37a50);
  }
  DVar3 = GetCurrentThreadId();
  do {
    FUN_0056da60(&DAT_00a37a50,"..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxWindow.cpp",0x635)
    ;
    uVar1 = DAT_00a2fa4c;
    if (DAT_00a2fa40 == 0) {
      if ((DAT_00a37a4c == 0) || (DAT_00a2fa44 == DVar3)) goto LAB_0050e46d;
      if (DAT_00a2fa48 == DVar3) {
        if (DAT_00a37a4c != 1) {
          FUN_0056d420(&DAT_00a2fa48,&DAT_00a2fa50,DAT_00a37a4c * 8 + -8);
          (&DAT_00a2fa44)[DAT_00a37a4c * 2] = uVar1;
          (&DAT_00a2fa40)[DAT_00a37a4c * 2] = 0;
        }
        DAT_00a37a4c = DAT_00a37a4c + -1;
LAB_0050e46d:
        DAT_00a2fa3c = DAT_00a2fa3c + 1;
        DAT_00a2fa40 = 1;
        DAT_00a2fa44 = DVar3;
        FUN_0056dac0(&DAT_00a37a50);
        return;
      }
    }
    else if (DAT_00a2fa44 == DVar3) goto LAB_0050e46d;
    if (DAT_00a37a4c == 0x1000) {
      FUN_0056dac0(&DAT_00a37a50);
      Sleep(1);
    }
    else {
      (&DAT_00a2fa48)[DAT_00a37a4c * 2] = DVar3;
      pvVar2 = (HANDLE)(&DAT_00a2fa4c)[DAT_00a37a4c * 2];
      DAT_00a37a4c = DAT_00a37a4c + 1;
      FUN_0056dac0(&DAT_00a37a50);
      WaitForSingleObject(pvVar2,0xffffffff);
      ResetEvent(pvVar2);
    }
  } while( true );
}

