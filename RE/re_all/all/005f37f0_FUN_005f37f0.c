
undefined4
FUN_005f37f0(undefined4 param_1,float param_2,float param_3,undefined4 param_4,float param_5,
            float param_6,int param_7)

{
  int *piVar1;
  float *pfVar2;
  int iVar3;
  undefined1 local_80 [128];
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  piVar1 = (int *)(&DAT_00dda4dc + param_7 * 4);
  if (*(int *)(&DAT_00dda4dc + param_7 * 4) < 0) {
    iVar3 = FUN_005f2360(0);
    *piVar1 = iVar3;
    if (iVar3 < 0) {
      FUN_005764b0((&PTR_s_Level_pso_00a05814)[param_7],0xffffffff,0x7ffd,local_80,0x80,0x4b0);
      FUN_0056bca0(&DAT_00802650,local_80);
      return 0xffffffff;
    }
    FUN_00580830(iVar3,piVar1);
  }
  pfVar2 = *(float **)(DAT_00ef1ba8 + 8);
  *pfVar2 = param_2;
  pfVar2[1] = 1.0 / (param_3 - param_2);
  pfVar2[2] = param_5;
  pfVar2[3] = param_6;
  *(undefined4 *)(DAT_00ef1ba8 + 0xc) = 1;
  FUN_005bc8e0(DAT_00ef1ba8);
  FUN_005f23c0(*piVar1,1,1,DAT_00dda4e4,0);
  return 0;
}

