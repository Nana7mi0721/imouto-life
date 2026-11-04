
void FUN_005f6180(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    iVar2 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x2c);
    *(int *)(param_1 + 0x18) = iVar2;
    uVar3 = (*(code *)**(undefined4 **)(param_1 + 4))(param_1,0,0x1000);
    *(undefined4 *)(iVar2 + 0x1c) = uVar3;
  }
  puVar1 = *(undefined4 **)(param_1 + 0x18);
  puVar1[2] = &LAB_005f6230;
  puVar1[3] = FUN_005f6240;
  puVar1[4] = FUN_005f6300;
  puVar1[5] = FUN_00680ec0;
  puVar1[6] = FUN_0065f670;
  puVar1[9] = param_2;
  iVar2 = (*(code *)*param_2)(param_2[6]);
  (**(code **)(puVar1[9] + 4))(*(undefined4 *)(puVar1[9] + 0x18),0,0,2);
  iVar4 = (**(code **)puVar1[9])(((undefined4 *)puVar1[9])[6]);
  puVar1[10] = iVar4 - iVar2;
  (**(code **)(puVar1[9] + 4))(*(undefined4 *)(puVar1[9] + 0x18),iVar2,iVar2 >> 0x1f,0);
  puVar1[1] = 0;
  *puVar1 = 0;
  return;
}

