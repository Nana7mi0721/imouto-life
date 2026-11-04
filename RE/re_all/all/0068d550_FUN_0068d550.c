
void FUN_0068d550(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x30);
  *(undefined4 **)(param_1 + 0x1b8) = puVar1;
  *puVar1 = &LAB_0068d6a0;
  *(undefined1 *)(puVar1 + 2) = 0;
  puVar1[10] = *(int *)(param_1 + 100) * *(int *)(param_1 + 0x5c);
  if (*(int *)(param_1 + 0x11c) == 2) {
    puVar1[1] = &LAB_0068d6c0;
    puVar1[3] = &LAB_0068d930;
    uVar2 = (**(code **)(*(int *)(param_1 + 4) + 4))(param_1,1,puVar1[10]);
    puVar1[8] = uVar2;
    FUN_0068d5e0(param_1);
    return;
  }
  puVar1[1] = FUN_0068d790;
  puVar1[3] = &LAB_0068d7d0;
  puVar1[8] = 0;
  FUN_0068d5e0(param_1);
  return;
}

