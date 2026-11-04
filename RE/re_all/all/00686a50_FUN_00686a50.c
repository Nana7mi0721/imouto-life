
void FUN_00686a50(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x20);
  *(undefined4 **)(param_1 + 0x188) = puVar1;
  *puVar1 = FUN_00686ba0;
  puVar1[1] = FUN_00686d40;
  puVar1[2] = &LAB_00687150;
  puVar1[3] = &LAB_00687500;
  puVar1[4] = FUN_00687520;
  puVar1[5] = FUN_00686ab0;
  puVar1[6] = &LAB_00686b80;
  puVar1[7] = 0;
  return;
}

