
void FUN_0066cd80(int param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  puVar3 = param_2 + *(int *)(param_1 + 4);
  puVar1 = param_2;
  if (*(char *)(param_1 + 10) == '\x02') {
    if (*(char *)(param_1 + 9) == '\b') {
      if (param_3 == 0) {
        puVar2 = param_2 + 2;
        puVar1 = param_2 + 1;
      }
      else {
        puVar2 = param_2 + 1;
      }
      for (; puVar2 < puVar3; puVar2 = puVar2 + 2) {
        *puVar1 = *puVar2;
        puVar1 = puVar1 + 1;
      }
      *(undefined1 *)(param_1 + 0xb) = 8;
    }
    else {
      if (*(char *)(param_1 + 9) != '\x10') {
        return;
      }
      if (param_3 == 0) {
        puVar2 = param_2 + 4;
        puVar1 = param_2 + 2;
      }
      else {
        puVar2 = param_2 + 2;
      }
      for (; puVar2 < puVar3; puVar2 = puVar2 + 4) {
        *puVar1 = *puVar2;
        puVar1[1] = puVar2[1];
        puVar1 = puVar1 + 2;
      }
      *(undefined1 *)(param_1 + 0xb) = 0x10;
    }
    *(undefined1 *)(param_1 + 10) = 1;
    if (*(char *)(param_1 + 8) == '\x04') {
      *(undefined1 *)(param_1 + 8) = 0;
      *(int *)(param_1 + 4) = (int)puVar1 - (int)param_2;
      return;
    }
  }
  else {
    if (*(char *)(param_1 + 10) != '\x04') {
      return;
    }
    if (*(char *)(param_1 + 9) == '\b') {
      if (param_3 == 0) {
        puVar2 = param_2 + 4;
        puVar1 = param_2 + 3;
      }
      else {
        puVar2 = param_2 + 1;
      }
      for (; puVar2 < puVar3; puVar2 = puVar2 + 4) {
        *puVar1 = *puVar2;
        puVar1[1] = puVar2[1];
        puVar1[2] = puVar2[2];
        puVar1 = puVar1 + 3;
      }
      *(undefined1 *)(param_1 + 0xb) = 0x18;
    }
    else {
      if (*(char *)(param_1 + 9) != '\x10') {
        return;
      }
      if (param_3 == 0) {
        puVar2 = param_2 + 8;
        puVar1 = param_2 + 6;
      }
      else {
        puVar2 = param_2 + 2;
      }
      for (; puVar2 < puVar3; puVar2 = puVar2 + 8) {
        *puVar1 = *puVar2;
        puVar1[1] = puVar2[1];
        puVar1[2] = puVar2[2];
        puVar1[3] = puVar2[3];
        puVar1[4] = puVar2[4];
        puVar1[5] = puVar2[5];
        puVar1 = puVar1 + 6;
      }
      *(undefined1 *)(param_1 + 0xb) = 0x30;
    }
    *(undefined1 *)(param_1 + 10) = 3;
    if (*(char *)(param_1 + 8) == '\x06') {
      *(undefined1 *)(param_1 + 8) = 2;
    }
  }
  *(int *)(param_1 + 4) = (int)puVar1 - (int)param_2;
  return;
}

