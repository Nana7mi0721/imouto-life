
void __fastcall FUN_004c28d0(int param_1)

{
  if (*(char *)(param_1 + 0xc2) != '\0') {
    FUN_005161e0(0xff,0xff,0xff);
    if ((*(int *)(param_1 + 0xf8) < 0) || (*(int *)(param_1 + 0xfc) < 1)) {
      if (*(char *)(param_1 + 0x108) == '\0') {
        *(undefined1 *)(param_1 + 0xc2) = 0;
      }
      else {
        *(undefined1 *)(param_1 + 0x108) = 0;
        FUN_00521db0(0,0,DAT_0084b230,DAT_0084b234,*(undefined4 *)(param_1 + 0x104),1);
        *(undefined1 *)(param_1 + 0xf2) = 0;
        *(undefined1 *)(param_1 + 0xc2) = 1;
        *(undefined4 *)(param_1 + 0xf8) = *(undefined4 *)(param_1 + 0xfc);
      }
    }
    else if (*(char *)(param_1 + 0xf4) == '\0') {
      FUN_005160d0(1,0xff);
      FUN_00528ab0(0,0,*(undefined4 *)(param_1 + 0x104),0,*(undefined4 *)(param_1 + 0x100),
                   0xff - (*(int *)(param_1 + 0xf8) * 0xff) / *(int *)(param_1 + 0xfc),0x40);
    }
    else {
      FUN_005160d0(1,(*(int *)(param_1 + 0xf8) * 0xff) / *(int *)(param_1 + 0xfc));
      FUN_0051e930(0,0,*(undefined4 *)(param_1 + 0x104),0);
    }
  }
  return;
}

