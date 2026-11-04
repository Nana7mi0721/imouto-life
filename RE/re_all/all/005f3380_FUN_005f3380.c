
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005f3380(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 *param_5,
            int param_6)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 local_80 [128];
  
  iVar3 = 0;
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (param_2 == 2) {
    iVar3 = 0;
  }
  else if (param_2 == 5) {
    iVar3 = 1;
  }
  param_6 = param_6 + ((uint)(param_4 == 1) + iVar3 * 2) * 2;
  iVar3 = param_6 * 4;
  piVar1 = (int *)(&DAT_00dda484 + iVar3);
  if (*(int *)(&DAT_00dda484 + iVar3) < 0) {
    iVar3 = FUN_005f2360(0);
    *piVar1 = iVar3;
    if (iVar3 < 0) {
      FUN_005764b0((&PTR_s_BrightClipLess_pso_00a057cc)[param_6],0xffffffff,0x7ffd,local_80,0x80,
                   0x4b0);
      FUN_0056bca0(&DAT_00802650,local_80);
      return 0xffffffff;
    }
    FUN_00580830(iVar3,piVar1);
  }
  puVar2 = *(undefined4 **)(DAT_00ef1ba8 + 8);
  *puVar2 = param_3;
  puVar2[1] = param_3;
  puVar2[2] = param_3;
  puVar2[3] = param_3;
  puVar2[4] = _DAT_0080264c;
  puVar2[5] = _DAT_00802648;
  puVar2[6] = _DAT_00802644;
  puVar2[7] = 0;
  if (param_5 != (undefined4 *)0x0) {
    puVar2[8] = *param_5;
    puVar2[9] = param_5[1];
    puVar2[10] = param_5[2];
    puVar2[0xb] = param_5[3];
  }
  *(undefined4 *)(DAT_00ef1ba8 + 0xc) = 1;
  FUN_005bc8e0(DAT_00ef1ba8);
  FUN_005f23c0(*piVar1,0,1,0xffffffff,0);
  return 0;
}

