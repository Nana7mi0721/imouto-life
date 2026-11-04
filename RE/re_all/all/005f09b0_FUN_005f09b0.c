
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005f09b0(undefined4 param_1,float param_2,undefined4 *param_3,undefined4 *param_4,int param_5)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  float local_d0;
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
  
  fVar2 = (float)_DAT_0081ec30;
  iVar3 = FUN_00567b30();
  if (iVar3 == 0) {
    return 0xffffffff;
  }
  FUN_005160a0(0);
  piVar1 = (int *)(&DAT_00dda4ec + param_5 * 4);
  if (*piVar1 < 0) {
    iVar3 = FUN_005ee300(0);
    *piVar1 = iVar3;
    if (iVar3 < 0) {
      FUN_005764b0((&PTR_s_TwoColor_pso_00a056d4)[param_5],0xffffffff,0x7ffd,local_80,0x80,0x4b0);
      FUN_0056bca0(&DAT_00802650,local_80);
      return 0xffffffff;
    }
    FUN_00580830(iVar3,piVar1);
  }
  local_ac = DAT_00a38dd8;
  local_a8 = DAT_00a38ddc;
  FUN_0059c240(&DAT_00ddb600,3);
  FUN_0056d420(local_a4,&DAT_00a38d78,4);
  local_dc = _DAT_0080264c;
  local_d8 = _DAT_00802648;
  local_84 = 1;
  local_d4 = _DAT_00802644;
  local_cc = *param_3;
  local_c8 = param_3[1];
  local_c4 = param_3[2];
  local_c0 = param_3[3];
  local_bc = *param_4;
  local_b8 = param_4[1];
  local_b4 = param_4[2];
  local_b0 = param_4[3];
  local_d0 = param_2 / fVar2;
  FUN_0059cb80(&DAT_00ddb600,3,1,0,&local_dc,3,0);
  FUN_00516d40(*piVar1);
  FUN_005ee5d0(1,0);
  FUN_005ee580();
  FUN_0059cc80(&DAT_00ddb600,3,1,0,3);
  return 0;
}

