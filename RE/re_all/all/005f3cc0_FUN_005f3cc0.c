
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005f3cc0(int param_1,int param_2)

{
  int *piVar1;
  float *pfVar2;
  bool bVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  float local_a8;
  float local_a4;
  float local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  float local_88;
  int local_84;
  undefined1 local_80 [128];
  
  if ((*(int *)(param_1 + 4) == 0xe) || (*(int *)(param_1 + 4) == 0xf)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  iVar5 = (-(uint)bVar3 & 2) + (uint)(-1 < param_2);
  piVar1 = (int *)(&DAT_00dda50c + iVar5 * 4);
  if (*(int *)(&DAT_00dda50c + iVar5 * 4) < 0) {
    iVar6 = FUN_005f2360(0);
    *piVar1 = iVar6;
    if (iVar6 < 0) {
      FUN_005764b0((&PTR_s_Y2uv2ToRgb_pso_00a0583c)[iVar5],0xffffffff,0x7ffd,local_80,0x80,0x4b0);
      FUN_0056bca0(&DAT_00802650,local_80);
      return 0xffffffff;
    }
    FUN_00580830(iVar6,piVar1);
  }
  if ((-1 < param_2) || (bVar3)) {
    FUN_00515880(*(undefined4 *)(param_1 + 8),&local_84,&local_90);
    FUN_005159a0(*(undefined4 *)(param_1 + 8),&local_8c,&local_94);
    pfVar2 = *(float **)(DAT_00ef1ba8 + 8);
    local_a0 = (float)local_84 / (float)local_8c;
    local_88 = (float)local_90 / (float)local_94;
    if (param_2 < 0) {
      fVar4 = 0.0;
      *pfVar2 = 0.0;
      pfVar2[1] = 0.0;
      pfVar2[2] = local_a0 * (float)_DAT_00804a60;
    }
    else {
      FUN_00515880(param_2,&local_9c,&local_98);
      FUN_005159a0(param_2,&local_a8,&local_a4);
      local_a8 = (float)local_9c / (float)(int)local_a8;
      *pfVar2 = local_a8 / local_a0;
      local_a4 = (float)local_98 / (float)(int)local_a4;
      pfVar2[1] = local_a4 / local_88;
      fVar4 = (float)_DAT_00804a60;
      pfVar2[2] = local_a0 * fVar4;
      fVar4 = fVar4 * local_a8;
    }
    pfVar2[3] = fVar4;
    *(undefined4 *)(DAT_00ef1ba8 + 0xc) = 1;
    FUN_005bc8e0(DAT_00ef1ba8);
  }
  FUN_005f23c0(*piVar1,0,1,param_2,0);
  return 0;
}

