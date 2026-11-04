
int __thiscall
FUN_005fff30(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  
  FUN_00602f50(param_2,param_3);
  *(undefined ***)(param_1 + 0xc) = &PTR_LAB_00803234;
  *(undefined ***)(param_1 + 0x10) = &PTR_LAB_00803220;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = *param_5;
  *(undefined4 *)(param_1 + 0x2c) = param_5[1];
  *(undefined4 *)(param_1 + 0x30) = param_5[2];
  uVar1 = param_5[3];
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x38) = param_4;
  *(undefined4 *)(param_1 + 0x48) = 1;
  return param_1;
}

