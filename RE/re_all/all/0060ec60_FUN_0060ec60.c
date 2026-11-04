
void __fastcall FUN_0060ec60(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_008040cc;
  if (*(char *)(param_1 + 3) != '\0') {
    piVar1 = (int *)param_1[2];
    if (piVar1[2] == 0) {
      if (((char)piVar1[4] == '\0') && (*piVar1 != 0)) {
        FUN_00646b80(*piVar1);
      }
      *piVar1 = 0;
      piVar1[2] = 0;
    }
    piVar1 = (int *)param_1[2];
    if (piVar1[2] == 0) {
      if (((char)piVar1[4] == '\0') && (*piVar1 != 0)) {
        FUN_00646b80(*piVar1);
      }
      *piVar1 = 0;
      piVar1[2] = 0;
    }
    FUN_00646b80(param_1[2]);
  }
  if (*(char *)(param_1 + 7) != '\0') {
    FUN_00646b80(*(undefined4 *)(param_1[6] + 0x10));
    FUN_00646b80(param_1[6]);
  }
  if (*(char *)(param_1 + 5) != '\0') {
    FUN_00646b80(*(undefined4 *)(param_1[4] + 0x10));
    FUN_00646b80(param_1[4]);
  }
  (*(code *)**(undefined4 **)param_1[10])(0);
  FUN_00646b80(param_1[10]);
  (*(code *)**(undefined4 **)param_1[0xb])(0);
  FUN_00646b80(param_1[0xb]);
  (*(code *)**(undefined4 **)param_1[0xc])(0);
  FUN_00646b80(param_1[0xc]);
  (*(code *)**(undefined4 **)param_1[0xd])(0);
  FUN_00646b80(param_1[0xd]);
  (*(code *)**(undefined4 **)param_1[0xe])(0);
  FUN_00646b80(param_1[0xe]);
  (*(code *)**(undefined4 **)param_1[0xf])(0);
  FUN_00646b80(param_1[0xf]);
  (*(code *)**(undefined4 **)param_1[0x10])(0);
  FUN_00646b80(param_1[0x10]);
  (*(code *)**(undefined4 **)param_1[0x12])(0);
  FUN_00646b80(param_1[0x12]);
  (*(code *)**(undefined4 **)param_1[0x13])(0);
  FUN_00646b80(param_1[0x13]);
  (*(code *)**(undefined4 **)param_1[0x11])(0);
  FUN_00646b80(param_1[0x11]);
  (*(code *)**(undefined4 **)param_1[0x15])(0);
  FUN_00646b80(param_1[0x15]);
  (*(code *)**(undefined4 **)param_1[0x14])(0);
  FUN_00646b80(param_1[0x14]);
  FUN_00646b80(param_1[8]);
  (*(code *)**(undefined4 **)param_1[9])(0);
  FUN_00646b80(param_1[9]);
  *param_1 = &PTR_LAB_008040f0;
  return;
}

