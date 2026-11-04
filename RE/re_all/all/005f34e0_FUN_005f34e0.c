
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005f34e0(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  float *pfVar2;
  float fVar3;
  int iVar4;
  undefined1 local_80 [128];
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  piVar1 = (int *)(&DAT_00dda4a4 + param_4 * 4);
  if (*(int *)(&DAT_00dda4a4 + param_4 * 4) < 0) {
    iVar4 = FUN_005f2360(0);
    *piVar1 = iVar4;
    if (iVar4 < 0) {
      FUN_005764b0((&PTR_s_BrightnessScale_pso_00a057ec)[param_4],0xffffffff,0x7ffd,local_80,0x80,
                   0x4b0);
      FUN_0056bca0(&DAT_00802650,local_80);
      return 0xffffffff;
    }
    FUN_00580830(iVar4,piVar1);
  }
  fVar3 = (float)_DAT_0081ec30;
  pfVar2 = *(float **)(DAT_00ef1ba8 + 8);
  *pfVar2 = (float)param_2 / fVar3;
  pfVar2[1] = fVar3 / (float)(param_3 - param_2);
  pfVar2[2] = 0.0;
  pfVar2[3] = 0.0;
  *(undefined4 *)(DAT_00ef1ba8 + 0xc) = 1;
  FUN_005bc8e0(DAT_00ef1ba8);
  FUN_005f23c0(*piVar1,0,1,0xffffffff,0);
  return 0;
}

