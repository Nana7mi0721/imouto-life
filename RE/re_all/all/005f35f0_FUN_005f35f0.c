
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005f35f0(undefined4 param_1,int param_2,undefined4 param_3,float param_4,undefined4 param_5,
            int param_6)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 local_80 [128];
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  param_6 = param_6 + param_2 * 2;
  iVar4 = param_6 * 4;
  piVar1 = (int *)(&DAT_00dda4b8 + iVar4);
  if (*(int *)(&DAT_00dda4b8 + iVar4) < 0) {
    iVar4 = FUN_005f2360(0);
    *piVar1 = iVar4;
    if (iVar4 < 0) {
      FUN_005764b0((&PTR_s_Hsb_HSB_BASE_pso_00a057f4)[param_6],0xffffffff,0x7ffd,local_80,0x80,0x4b0
                  );
      FUN_0056bca0(&DAT_00802650,local_80);
      return 0xffffffff;
    }
    FUN_00580830(iVar4,piVar1);
  }
  puVar2 = *(undefined4 **)(DAT_00ef1ba8 + 8);
  *puVar2 = param_3;
  if (0.0 < param_4) {
    param_4 = param_4 * (float)_DAT_007d5558;
  }
  puVar2[1] = param_4;
  puVar2[2] = param_5;
  puVar2[3] = 0;
  uVar3 = _DAT_007d589c;
  puVar2[4] = _DAT_007d589c;
  puVar2[5] = uVar3;
  puVar2[6] = uVar3;
  puVar2[7] = uVar3;
  puVar2[8] = 0x3f800000;
  puVar2[9] = 0x3f800000;
  puVar2[10] = 0x3f800000;
  puVar2[0xb] = 0x3f800000;
  *(undefined4 *)(DAT_00ef1ba8 + 0xc) = 1;
  FUN_005bc8e0(DAT_00ef1ba8);
  FUN_005f23c0(*piVar1,0,1,0xffffffff,0);
  return 0;
}

