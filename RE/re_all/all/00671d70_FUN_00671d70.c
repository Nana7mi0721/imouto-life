
void FUN_00671d70(int param_1,int param_2,undefined1 param_3)

{
  undefined1 *puVar1;
  
  if (param_1 != 0) {
    if ((((*(byte *)(param_1 + 0x268) & 4) == 0) || (param_2 != 0x40)) && (param_2 != 0)) {
      FUN_00668620(param_1,s_Unknown_custom_filter_method_00a0c93c);
    }
    else {
      switch(param_3) {
      case 1:
        *(undefined1 *)(param_1 + 0x156) = 0x10;
        break;
      case 2:
        *(undefined1 *)(param_1 + 0x156) = 0x20;
        break;
      case 3:
        *(undefined1 *)(param_1 + 0x156) = 0x40;
        break;
      case 4:
        *(undefined1 *)(param_1 + 0x156) = 0x80;
        break;
      case 5:
      case 6:
      case 7:
        FUN_00668a00(param_1,s_Unknown_row_filter_for_method_0_00a0c9d0);
      case 0:
        *(undefined1 *)(param_1 + 0x156) = 8;
        break;
      default:
        *(undefined1 *)(param_1 + 0x156) = param_3;
      }
      if (*(int *)(param_1 + 0x124) != 0) {
        if (((*(byte *)(param_1 + 0x156) & 0x10) != 0) && (*(int *)(param_1 + 0x128) == 0)) {
          puVar1 = (undefined1 *)FUN_0066caf0(param_1,*(int *)(param_1 + 0x110) + 1);
          *(undefined1 **)(param_1 + 0x128) = puVar1;
          *puVar1 = 1;
        }
        if (((*(byte *)(param_1 + 0x156) & 0x20) != 0) && (*(int *)(param_1 + 300) == 0)) {
          if (*(int *)(param_1 + 0x120) == 0) {
            FUN_006687b0(param_1,s_Can_t_add_Up_filter_after_starti_00a0c9ac);
            *(byte *)(param_1 + 0x156) = *(byte *)(param_1 + 0x156) & 0xdf;
          }
          else {
            puVar1 = (undefined1 *)FUN_0066caf0(param_1,*(int *)(param_1 + 0x110) + 1);
            *(undefined1 **)(param_1 + 300) = puVar1;
            *puVar1 = 2;
          }
        }
        if (((*(byte *)(param_1 + 0x156) & 0x40) != 0) && (*(int *)(param_1 + 0x130) == 0)) {
          if (*(int *)(param_1 + 0x120) == 0) {
            FUN_006687b0(param_1,s_Can_t_add_Average_filter_after_s_00a0c984);
            *(byte *)(param_1 + 0x156) = *(byte *)(param_1 + 0x156) & 0xbf;
          }
          else {
            puVar1 = (undefined1 *)FUN_0066caf0(param_1,*(int *)(param_1 + 0x110) + 1);
            *(undefined1 **)(param_1 + 0x130) = puVar1;
            *puVar1 = 3;
          }
        }
        if (((*(byte *)(param_1 + 0x156) & 0x80) != 0) && (*(int *)(param_1 + 0x134) == 0)) {
          if (*(int *)(param_1 + 0x120) == 0) {
            FUN_006687b0(param_1,s_Can_t_add_Paeth_filter_after_sta_00a0c95c);
            *(byte *)(param_1 + 0x156) = *(byte *)(param_1 + 0x156) & 0x7f;
          }
          else {
            puVar1 = (undefined1 *)FUN_0066caf0(param_1,*(int *)(param_1 + 0x110) + 1);
            *(undefined1 **)(param_1 + 0x134) = puVar1;
            *puVar1 = 4;
          }
        }
        if (*(char *)(param_1 + 0x156) == '\0') {
          *(undefined1 *)(param_1 + 0x156) = 8;
          return;
        }
      }
    }
  }
  return;
}

