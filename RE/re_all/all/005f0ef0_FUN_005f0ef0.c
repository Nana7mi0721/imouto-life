
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005f0ef0(int param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  int local_c8;
  int local_c4;
  float local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined1 local_a4 [32];
  undefined4 local_84;
  undefined1 local_80 [128];
  
  if ((*(int *)(param_1 + 4) == 0xe) || (*(int *)(param_1 + 4) == 0xf)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  iVar3 = FUN_00567b30();
  if (iVar3 == 0) {
    return 0xffffffff;
  }
  FUN_005160a0(0);
  iVar3 = (-(uint)bVar2 & 2) + (uint)(-1 < param_2);
  piVar1 = (int *)(&DAT_00dda50c + iVar3 * 4);
  if (*(int *)(&DAT_00dda50c + iVar3 * 4) < 0) {
    iVar4 = FUN_005ee300(0);
    *piVar1 = iVar4;
    if (iVar4 < 0) {
      FUN_005764b0((&PTR_s_Y2uv2ToRgb_pso_00a056f4)[iVar3],0xffffffff,0x7ffd,local_80,0x80,0x4b0);
      FUN_0056bca0(&DAT_00802650,local_80);
      return 0xffffffff;
    }
    FUN_00580830(iVar4,piVar1);
  }
  local_ac = DAT_00a38dd8;
  local_a8 = DAT_00a38ddc;
  FUN_0059c240(&DAT_00ddb600,3);
  FUN_0056d420(local_a4,&DAT_00a38d78,8);
  local_84 = 2;
  if ((-1 < param_2) || (bVar2)) {
    FUN_00515880(*(undefined4 *)(param_1 + 8),&local_bc,&local_b0);
    FUN_005159a0(*(undefined4 *)(param_1 + 8),&local_c4,&local_b8);
    local_dc = (float)local_bc / (float)local_c4;
    local_c0 = (float)local_b0 / (float)local_b8;
    if (param_2 < 0) {
      local_cc = 0.0;
      local_d8 = 0.0;
      local_d4 = 0.0;
      local_d0 = local_dc * (float)_DAT_00804a60;
    }
    else {
      FUN_00515880(param_2,&local_b4,&local_c8);
      FUN_005159a0(param_2,&local_e4,&local_e0);
      local_e4 = (float)local_b4 / (float)(int)local_e4;
      local_d8 = local_e4 / local_dc;
      local_e0 = (float)local_c8 / (float)(int)local_e0;
      local_d4 = local_e0 / local_c0;
      local_d0 = local_dc * (float)_DAT_00804a60;
      local_cc = (float)_DAT_00804a60 * local_e4;
    }
    FUN_0059cb80(&DAT_00ddb600,3,1,0,&local_d8,1,0);
  }
  FUN_00516d40(*piVar1);
  FUN_00516bd0(1,param_2);
  FUN_005ee5d0(1,0);
  FUN_005ee580();
  if (-1 < param_2) {
    FUN_0059cc80(&DAT_00ddb600,3,1,0,1);
  }
  return 0;
}

