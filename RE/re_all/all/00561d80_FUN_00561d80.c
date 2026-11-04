
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00561d80(void)

{
  float fVar1;
  ushort uVar2;
  int iVar3;
  ushort in_FPUControlWord;
  float local_1c;
  undefined1 local_18 [4];
  int local_14;
  float local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_00a834f0 == 0) {
    if (DAT_00a834f8 == 0) {
      DAT_00a834f8 = 0xac44;
    }
    if (DAT_00a834fc == 0) {
      _DAT_00a83500 = 0x3f800000;
    }
    FUN_005808a0(3,0x2628,0x8000,FUN_0055bc80,FUN_0055f7d0,L"Sound");
    FUN_005808a0(4,0x250,0x2000,FUN_005e2310,FUN_00552080,L"SoftSound");
    FUN_005808a0(5,0x4c,0x100,&LAB_0055b940,FUN_00561b80,L"Music");
    FUN_0056da30(&DAT_00a83570);
    FUN_0056da30(&DAT_00a83a30);
    FUN_0056da30(&DAT_00a837b0);
    FUN_005807b0(&DAT_00a83550,&DAT_00a83560);
    FUN_005807b0(&DAT_00a83790,&DAT_00a837a0);
    FUN_005807b0(&DAT_00a839d0,&DAT_00a839e0);
    FUN_005807b0(&DAT_00a839f0,&DAT_00a83a00);
    FUN_005807b0(&DAT_00a83a10,&DAT_00a83a20);
    local_10 = 0.0;
    do {
      fVar1 = local_10;
      local_10 = ((float)(int)local_10 * (float)_DAT_007d56c0 +
                 (float)(int)local_10 * (float)_DAT_007d56c0) * (float)_DAT_007d62c8;
      FUN_0056d4d0(local_10,&local_1c,local_18);
      uVar2 = in_FPUControlWord | 0xc00;
      local_14 = (int)ROUND(local_1c * (float)_DAT_007d6810);
      (&DAT_00a8424c)[(int)fVar1] = (undefined2)local_14;
      local_10 = (float)((int)fVar1 + 1);
    } while ((int)local_10 < 0x10000);
    iVar3 = FUN_0057d0c0();
    if (-1 < iVar3) {
      _DAT_00a83c7c = 0x3f800000;
      _DAT_00a83c88 = 0x3f800000;
      DAT_00a83c74 = 0;
      DAT_00a83c78 = 0;
      DAT_00a83c84 = 0;
      DAT_00a83ca4 = 2;
      _DAT_00a83504 = 0;
      _DAT_00a83508 = 0;
      _DAT_00a8350c = 0;
      _DAT_00a83510 = 0;
      _DAT_00a83534 = _DAT_007d6808;
      _DAT_00a83514 = 0;
      _DAT_00a83538 = _DAT_007d6804;
      _DAT_00a83518 = 0x3f800000;
      _DAT_00a8353c = 0x3f800000;
      _DAT_00a83528 = 0;
      _DAT_00a83540 = _DAT_007d6800;
      _DAT_00a8352c = 0;
      _DAT_00a83530 = 0;
      DAT_00a834f0 = 1;
      local_c = 0x3f800000;
      _DAT_00a83544 = 0x3f800000;
      local_8 = 0;
      local_4 = 0;
      _DAT_00a83548 = 0;
      _DAT_00a8354c = 0;
      FUN_00580eb0(3,&LAB_00550c50,in_FPUControlWord,uVar2);
      _DAT_00a83c50 = 0xffffffff;
      if (DAT_00a834f0 != 0) {
        FUN_00580eb0(4,&LAB_005520d0,in_FPUControlWord,uVar2);
        if (DAT_00a834f0 != 0) {
          FUN_00580eb0(4,&LAB_005520e0,in_FPUControlWord,uVar2);
        }
      }
      iVar3 = FUN_0057de70();
      if (-1 < iVar3) {
        iVar3 = FUN_0055c780();
        return (-1 < iVar3) - 1;
      }
    }
  }
  return -1;
}

