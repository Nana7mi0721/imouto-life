
void FUN_00669790(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x9c) == 0) {
    switch(param_2) {
    default:
      *(char **)(param_1 + 0x9c) = s_unexpected_zlib_return_code_00a0bcf8;
      break;
    case 1:
      *(char **)(param_1 + 0x9c) = s_unexpected_end_of_LZ_stream_00a0bdbc;
      return;
    case 2:
      *(char **)(param_1 + 0x9c) = s_missing_LZ_dictionary_00a0bda4;
      return;
    case 0xfffffff9:
      *(char **)(param_1 + 0x9c) = s_unexpected_zlib_return_00a0bd14;
      return;
    case 0xfffffffa:
      *(char **)(param_1 + 0x9c) = s_unsupported_zlib_version_00a0bd2c;
      return;
    case 0xfffffffb:
      *(char **)(param_1 + 0x9c) = s_truncated_00a0bd48;
      return;
    case 0xfffffffc:
      *(char **)(param_1 + 0x9c) = s_insufficient_memory_00a0bd54;
      return;
    case 0xfffffffd:
      *(char **)(param_1 + 0x9c) = s_damaged_LZ_stream_00a0bd68;
      return;
    case 0xfffffffe:
      *(char **)(param_1 + 0x9c) = s_bad_parameters_to_zlib_00a0bd7c;
      return;
    case 0xffffffff:
      *(char **)(param_1 + 0x9c) = s_zlib_IO_error_00a0bd94;
      return;
    }
  }
  return;
}

