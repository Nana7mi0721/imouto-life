
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005f0580(int param_1,int param_2,undefined4 param_3,float param_4,undefined4 param_5,int param_6
            )

{
  int *piVar1;
  int iVar2;
  undefined4 local_dc;
  float local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined1 local_a4 [32];
  undefined4 local_84;
  undefined1 local_80 [128];
  
  iVar2 = FUN_00567b30();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  FUN_005160a0(0);
  iVar2 = 2;
  if (param_2 != 1) {
    iVar2 = *(int *)(param_1 + 0x1c);
  }
  param_6 = param_6 + iVar2 * 2;
  iVar2 = param_6 * 4;
  piVar1 = (int *)(&DAT_00dda4b8 + iVar2);
  if (*(int *)(&DAT_00dda4b8 + iVar2) < 0) {
    iVar2 = FUN_005ee300(0);
    *piVar1 = iVar2;
    if (iVar2 < 0) {
      FUN_005764b0((&PTR_s_Hsb_RGB_TO_HSB_pso_00a056ac)[param_6],0xffffffff,0x7ffd,local_80,0x80,
                   0x4b0);
      FUN_0056bca0(&DAT_00802650,local_80);
      return 0xffffffff;
    }
    FUN_00580830(iVar2,piVar1);
  }
  local_ac = DAT_00a38dd8;
  local_a8 = DAT_00a38ddc;
  FUN_0059c240(&DAT_00ddb600,3);
  FUN_0056d420(local_a4,&DAT_00a38d78,4);
  local_dc = param_3;
  local_d0 = 0;
  local_84 = 1;
  local_d8 = param_4;
  if (0.0 < param_4) {
    local_d8 = param_4 * (float)_DAT_007d5558;
  }
  local_d4 = param_5;
  local_cc = _DAT_007d589c;
  local_c8 = _DAT_007d589c;
  local_c4 = _DAT_007d589c;
  local_c0 = _DAT_007d589c;
  local_bc = 0x3f800000;
  local_b8 = 0x3f800000;
  local_b4 = 0x3f800000;
  local_b0 = 0x3f800000;
  FUN_0059cb80(&DAT_00ddb600,3,1,0,&local_dc,3,0);
  FUN_00516d40(*piVar1);
  FUN_005ee5d0(1,0);
  FUN_005ee580();
  FUN_0059cc80(&DAT_00ddb600,3,1,0,3);
  return 0;
}

