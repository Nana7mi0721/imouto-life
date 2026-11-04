
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005ef320(undefined4 param_1,float param_2,float param_3)

{
  int iVar1;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined1 local_a4 [32];
  undefined4 local_84;
  undefined1 local_80 [128];
  
  iVar1 = FUN_00567b30();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  FUN_005160a0(0);
  if (DAT_00dda4d0 < 0) {
    DAT_00dda4d0 = FUN_005ee300(0);
    if (DAT_00dda4d0 < 0) {
      FUN_005764b0(PTR_s_Mono_pso_00a05668,0xffffffff,0x7ffd,local_80,0x80,0x4b0);
      FUN_0056bca0(&DAT_00802650,local_80);
      return 0xffffffff;
    }
    FUN_00580830(DAT_00dda4d0,&DAT_00dda4d0);
  }
  local_ac = DAT_00a38dd8;
  local_a8 = DAT_00a38ddc;
  FUN_0059c240(&DAT_00ddb600,3);
  FUN_0056d420(local_a4,&DAT_00a38d78,4);
  local_cc = _DAT_0080264c;
  local_c8 = _DAT_00802648;
  local_c4 = _DAT_00802644;
  local_c0 = 0;
  local_84 = 1;
  local_bc = (float)_DAT_007d9bc0 * param_3;
  local_b8 = (float)_DAT_007d9bb0 * param_2 - param_3 * (float)_DAT_007d9ba8;
  local_b4 = param_2 * (float)_DAT_007d9ba0;
  local_b0 = 0;
  FUN_0059cb80(&DAT_00ddb600,3,1,0,&local_cc,2,0);
  FUN_00516d40(DAT_00dda4d0);
  FUN_005ee5d0(1,0);
  FUN_005ee580();
  FUN_0059cc80(&DAT_00ddb600,3,1,0,2);
  return 0;
}

