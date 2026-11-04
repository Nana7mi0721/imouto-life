
undefined4 FUN_0060a6f0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  FUN_0056da60(param_1 + 0x34,s_D__DxLib_Develop_Source_Library__00a06048,0x39af);
  uVar3 = (*(code *)**(undefined4 **)(param_1 + 0x24))((*(undefined4 **)(param_1 + 0x24))[6]);
  uVar2 = (uint)((ulonglong)uVar3 >> 0x20);
  if ((uVar2 < *(uint *)(param_1 + 0x2c)) ||
     ((uVar2 <= *(uint *)(param_1 + 0x2c) && ((uint)uVar3 < *(uint *)(param_1 + 0x28))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  *param_2 = uVar1;
  FUN_0056dac0(param_1 + 0x34);
  return 0;
}

