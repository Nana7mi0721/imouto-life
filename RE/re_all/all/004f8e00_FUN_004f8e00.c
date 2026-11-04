
undefined4 FUN_004f8e00(int param_1,undefined4 param_2,uint *param_3)

{
  undefined4 uVar1;
  int iVar2;
  byte local_9;
  int local_8;
  
  local_8 = (**(code **)(param_1 + 4))(*(undefined4 *)(param_1 + 0x1c),param_2,&local_9,1);
  if (local_8 == 1) {
    *param_3 = (uint)local_9;
    uVar1 = 0;
  }
  else {
    iVar2 = (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_1 + 0x1c),param_2);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

