
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005f3900(undefined4 param_1,float param_2,undefined4 *param_3,undefined4 *param_4,int param_5)

{
  int *piVar1;
  undefined4 *puVar2;
  float fVar3;
  int iVar4;
  undefined1 local_80 [128];
  
  fVar3 = (float)_DAT_0081ec30;
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  piVar1 = (int *)(&DAT_00dda4ec + param_5 * 4);
  if (*(int *)(&DAT_00dda4ec + param_5 * 4) < 0) {
    iVar4 = FUN_005f2360(0);
    *piVar1 = iVar4;
    if (iVar4 < 0) {
      FUN_005764b0((&PTR_s_TwoColor_pso_00a0581c)[param_5],0xffffffff,0x7ffd,local_80,0x80,0x4b0);
      FUN_0056bca0(&DAT_00802650,local_80);
      return 0xffffffff;
    }
    FUN_00580830(iVar4,piVar1);
  }
  puVar2 = *(undefined4 **)(DAT_00ef1ba8 + 8);
  *puVar2 = _DAT_0080264c;
  puVar2[1] = _DAT_00802648;
  puVar2[2] = _DAT_00802644;
  puVar2[3] = param_2 / fVar3;
  puVar2[4] = *param_3;
  puVar2[5] = param_3[1];
  puVar2[6] = param_3[2];
  puVar2[7] = param_3[3];
  puVar2[8] = *param_4;
  puVar2[9] = param_4[1];
  puVar2[10] = param_4[2];
  puVar2[0xb] = param_4[3];
  *(undefined4 *)(DAT_00ef1ba8 + 0xc) = 1;
  FUN_005bc8e0(DAT_00ef1ba8);
  FUN_005f23c0(*piVar1,0,1,0xffffffff,0);
  return 0;
}

