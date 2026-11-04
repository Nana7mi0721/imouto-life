
void FUN_006790b0(undefined4 param_1,undefined2 *param_2)

{
  undefined1 local_8 [2];
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  
  if ((((*(byte *)(param_2 + 1) < 0xd) && (*(byte *)(param_2 + 1) != 0)) &&
      (*(byte *)((int)param_2 + 3) < 0x20)) &&
     (((*(byte *)((int)param_2 + 3) != 0 && (*(byte *)(param_2 + 2) < 0x18)) &&
      (*(byte *)(param_2 + 3) < 0x3d)))) {
    FUN_00677270(local_8,*param_2);
    local_6 = *(undefined1 *)(param_2 + 1);
    local_4 = *(undefined1 *)(param_2 + 2);
    local_5 = *(undefined1 *)((int)param_2 + 3);
    local_3 = *(undefined1 *)((int)param_2 + 5);
    local_2 = *(undefined1 *)(param_2 + 3);
    FUN_00677430(param_1,0x74494d45,local_8,7);
    return;
  }
  FUN_006687b0(param_1,s_Invalid_time_specified_for_tIME_c_00a0d96c);
  return;
}

