
void FUN_006868c0(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x66];
  if (*(char *)(iVar1 + 8) == '\0') {
    if ((*(char *)((int)param_1 + 0x4a) != '\0') && (param_1[0x1d] == 0)) {
      if (((char)param_1[0x14] == '\0') || (*(char *)((int)param_1 + 0x5a) == '\0')) {
        if ((char)param_1[0x16] == '\0') {
          *(undefined4 *)(*param_1 + 0x14) = 0x2f;
          (**(code **)*param_1)(param_1);
        }
        else {
          param_1[0x70] = *(int *)(iVar1 + 0x14);
        }
      }
      else {
        param_1[0x70] = *(int *)(iVar1 + 0x18);
        *(undefined1 *)(iVar1 + 8) = 1;
      }
    }
    (**(code **)param_1[0x6d])(param_1);
    (**(code **)(param_1[0x68] + 8))(param_1);
    if (*(char *)((int)param_1 + 0x41) == '\0') {
      if (*(char *)(iVar1 + 0x10) == '\0') {
        (**(code **)param_1[0x6f])(param_1);
      }
      (**(code **)param_1[0x6e])(param_1);
      if (*(char *)((int)param_1 + 0x4a) != '\0') {
        (**(code **)param_1[0x70])(param_1,*(undefined1 *)(iVar1 + 8));
      }
      (**(code **)param_1[0x69])(param_1,-(*(char *)(iVar1 + 8) != '\0') & 3);
      (**(code **)param_1[0x67])(param_1,0);
    }
  }
  else {
    *(undefined1 *)(iVar1 + 8) = 0;
    (**(code **)param_1[0x70])(param_1,0);
    (**(code **)param_1[0x69])(param_1,2);
    (**(code **)param_1[0x67])(param_1,2);
  }
  if (param_1[2] != 0) {
    *(undefined4 *)(param_1[2] + 0xc) = *(undefined4 *)(iVar1 + 0xc);
    *(uint *)(param_1[2] + 0x10) = (*(char *)(iVar1 + 8) != '\0') + 1 + *(int *)(iVar1 + 0xc);
    if (((char)param_1[0x10] != '\0') && (*(char *)(param_1[0x6a] + 0x11) == '\0')) {
      *(uint *)(param_1[2] + 0x10) =
           *(int *)(param_1[2] + 0x10) + (*(char *)((int)param_1 + 0x5a) != '\0') + 1;
    }
  }
  return;
}

