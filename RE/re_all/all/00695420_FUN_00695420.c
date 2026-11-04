
void FUN_00695420(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x20);
  *(undefined4 **)(param_1 + 0x178) = puVar1;
  *puVar1 = FUN_00695d40;
  puVar1[1] = FUN_006961c0;
  puVar1[2] = &LAB_006961f0;
  *(undefined1 *)((int)puVar1 + 0xd) = 0;
  FUN_00695510(param_1,param_2);
  if (*(int *)(param_1 + 0xcc) == 0) {
    *(undefined1 *)(param_1 + 0xfc) = 0;
    *(undefined4 *)(param_1 + 200) = 1;
  }
  else {
    FUN_00695910(param_1);
    if (*(int *)(param_1 + 0x16c) < 8) {
      FUN_00695cc0(param_1);
    }
  }
  if (((*(char *)(param_1 + 0xfc) != '\0') || (*(int *)(param_1 + 0x16c) < 8)) &&
     (*(char *)(param_1 + 0xd1) == '\0')) {
    *(undefined1 *)(param_1 + 0xd2) = 1;
  }
  if ((char)param_2 == '\0') {
    puVar1[4] = 0;
  }
  else if (*(char *)(param_1 + 0xd2) == '\0') {
    puVar1[4] = 2;
  }
  else {
    puVar1[4] = 1;
  }
  puVar1[7] = 0;
  puVar1[5] = 0;
  if (*(char *)(param_1 + 0xd2) == '\0') {
    puVar1[6] = *(undefined4 *)(param_1 + 200);
    return;
  }
  puVar1[6] = *(int *)(param_1 + 200) << 1;
  return;
}

