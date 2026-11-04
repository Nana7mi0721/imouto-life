
void FUN_00684da0(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x18);
  *(undefined4 **)(param_1 + 0x1a8) = puVar1;
  *puVar1 = FUN_006850b0;
  puVar1[1] = FUN_00685710;
  puVar1[2] = FUN_00684df0;
  puVar1[3] = &LAB_00685090;
  *(undefined1 *)(puVar1 + 4) = 0;
  *(undefined1 *)((int)puVar1 + 0x11) = 0;
  puVar1[5] = 1;
  return;
}

