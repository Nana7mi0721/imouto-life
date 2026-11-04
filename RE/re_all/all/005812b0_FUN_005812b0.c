
void FUN_005812b0(int param_1,int param_2,undefined4 *param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_3 == (undefined4 *)0x0) {
    local_4 = *(undefined4 *)(param_2 + 8);
    local_10 = 0;
    local_c = 0;
    local_8 = *(undefined4 *)(param_2 + 4);
    param_3 = &local_10;
  }
  FUN_00549b20(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(*(int *)(param_1 + 0x14) + 0xc),
               *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x14),*(undefined4 *)(param_2 + 0xc),
               *(undefined4 *)(*(int *)(param_2 + 0x14) + 0xc),
               *(undefined4 *)(*(int *)(param_2 + 0x14) + 0x14),0,0,0,param_4,param_5,param_3,0,0,0,
               0,0,0,0,0);
  return;
}

