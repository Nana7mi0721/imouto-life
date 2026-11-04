
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005f3a50(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 local_80 [128];
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  param_4 = param_4 + (uint)(param_3 != 0) * 2;
  iVar3 = param_4 * 4;
  piVar1 = (int *)(&DAT_00dda4f4 + iVar3);
  if (*(int *)(&DAT_00dda4f4 + iVar3) < 0) {
    iVar3 = FUN_005f2360(0);
    *piVar1 = iVar3;
    if (iVar3 < 0) {
      FUN_005764b0((&PTR_s_GradientMap_pso_00a05824)[param_4],0xffffffff,0x7ffd,local_80,0x80,0x4b0)
      ;
      FUN_0056bca0(&DAT_00802650,local_80);
      return 0xffffffff;
    }
    FUN_00580830(iVar3,piVar1);
  }
  puVar2 = *(undefined4 **)(DAT_00ef1ba8 + 8);
  *puVar2 = _DAT_0080264c;
  puVar2[1] = _DAT_00802648;
  puVar2[2] = _DAT_00802644;
  puVar2[3] = 0;
  *(undefined4 *)(DAT_00ef1ba8 + 0xc) = 1;
  FUN_005bc8e0(DAT_00ef1ba8);
  FUN_005f23c0(*piVar1,0,1,param_2,0);
  return 0;
}

