
undefined4
FUN_005f0840(undefined4 param_1,float param_2,float param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,int param_7)

{
  int *piVar1;
  int iVar2;
  float local_bc;
  float local_b8;
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
  piVar1 = (int *)(&DAT_00dda4dc + param_7 * 4);
  if (*(int *)(&DAT_00dda4dc + param_7 * 4) < 0) {
    iVar2 = FUN_005ee300(0);
    *piVar1 = iVar2;
    if (iVar2 < 0) {
      FUN_005764b0((&PTR_s_Level_pso_00a056cc)[param_7],0xffffffff,0x7ffd,local_80,0x80,0x4b0);
      FUN_0056bca0(&DAT_00802650,local_80);
      return 0xffffffff;
    }
    FUN_00580830(iVar2,piVar1);
  }
  local_ac = DAT_00a38dd8;
  local_a8 = DAT_00a38ddc;
  FUN_0059c240(&DAT_00ddb600,3);
  FUN_0056d420(local_a4,&DAT_00a38d78,4);
  local_bc = param_2;
  local_b8 = 1.0 / (param_3 - param_2);
  local_84 = 1;
  local_b4 = param_5;
  local_b0 = param_6;
  FUN_0059cb80(&DAT_00ddb600,3,1,0,&local_bc,1,0);
  FUN_00516d40(*piVar1);
  FUN_00516bd0(1,DAT_00dda4e4);
  FUN_005ee5d0(1,0);
  FUN_005ee580();
  FUN_0059cc80(&DAT_00ddb600,3,1,0,1);
  return 0;
}

