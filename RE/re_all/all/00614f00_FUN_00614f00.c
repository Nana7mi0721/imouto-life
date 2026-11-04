
undefined4 * __fastcall FUN_00614f00(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_4;
  
  *(undefined1 *)(param_1 + 5) = 1;
  param_1[4] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  *(undefined1 *)(param_1 + 0xc) = 1;
  param_1[0xb] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  *(undefined1 *)(param_1 + 0x11) = 1;
  param_1[0x10] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x12] = 0;
  *param_1 = &PTR_LAB_0080440c;
  if ((int)param_1[3] < 2) {
    iVar1 = FUN_00646b30(0x20,0x10);
    local_4 = param_1[2];
    if (0 < local_4) {
      puVar3 = (undefined4 *)(iVar1 + 8);
      do {
        if (puVar3 != (undefined4 *)0x8) {
          puVar2 = (undefined4 *)(param_1[4] + (-8 - iVar1) + (int)puVar3);
          puVar3[-2] = *puVar2;
          puVar3[-1] = puVar2[1];
          *puVar3 = puVar2[2];
          puVar3[1] = puVar2[3];
        }
        puVar3 = puVar3 + 4;
        local_4 = local_4 + -1;
      } while (local_4 != 0);
    }
    if (param_1[4] != 0) {
      if (*(char *)(param_1 + 5) != '\0') {
        FUN_00646b80(param_1[4]);
      }
      param_1[4] = 0;
    }
    param_1[4] = iVar1;
    *(undefined1 *)(param_1 + 5) = 1;
    param_1[3] = 2;
  }
  FUN_00615260();
  return param_1;
}

