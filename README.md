# Job Application Management System

A comprehensive C++ console application for managing job applications with full CRUD (Create, Read, Update, Delete) functionality.

## Overview

This Job Application Management System allows users to efficiently track their job search progress by storing, organizing, and managing job application data. The system provides an intuitive interface for adding new applications, viewing existing ones, editing application details, and removing outdated entries.

## Features

- **Add Applications**: Create new job application entries with comprehensive details
- **View Applications**: Display all stored applications in an organized format
- **Search & Filter**: Find specific applications by company, position, or status
- **Edit Applications**: Modify existing application information
- **Delete Applications**: Remove applications that are no longer relevant
- **Data Persistence**: Store application data in files for long-term access
- **Status Tracking**: Monitor application progress (Applied, Interview, Rejected, Offer, etc.)

## System Requirements

- C++20 compatible compiler
- GCC 10+ or Clang 10+ or MSVC 2019+
- CMake 3.16 or later
- Minimum 50MB available disk space
- Console/Terminal environment

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/job-application-manager.git
   cd job-application-manager
   ```

2. Build with CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. Run the executable:
   ```bash
   ./job_manager
   ```

## Usage

### Main Menu Options

1. **Add New Application** - Enter details for a new job application
2. **View All Applications** - Display a list of all stored applications
3. **Search Applications** - Find applications by specific criteria
4. **Edit Application** - Modify an existing application's details
5. **Delete Application** - Remove an application from the system
6. **Export Data** - Save applications to external file formats
7. **Exit** - Close the application

### Application Data Fields

Each job application entry contains:
- Company Name
- Position Title  
- Application Date
- Application Status
- Job Description/Notes
- Salary Range
- Contact Information
- Application Deadline
- Interview Dates
- Follow-up Notes

### Sample Workflow

```bash
# Start the application
./job_manager

# Add a new job application
> Select option 1
> Enter company: "Tech Corp"
> Enter position: "Software Developer"
> Enter status: "Applied"
> [Continue with remaining fields...]

# View all applications
> Select option 2
> [Displays formatted list of all applications]

# Edit an existing application
> Select option 4
> Enter application ID: 1
> [Modify desired fields]
```

## File Structure

```
job-application-manager/
├── src/
│   ├── main.cpp           # Main program entry point
│   ├── application.h      # Application class header
│   ├── application.cpp    # Application class implementation
│   ├── manager.h          # Manager class header
│   └── manager.cpp        # Manager class implementation
├── include/               # Header files directory
├── data/
│   └── applications.dat   # Data storage file
├── docs/
│   └── user_guide.md      # Detailed user guide
├── tests/
│   └── test_manager.cpp   # Unit tests
├── CMakeLists.txt         # CMake configuration
└── README.md             # This file
```

## Data Storage

The system uses binary file storage for efficient data persistence. Application data is automatically saved to `data/applications.dat` and loaded on program startup. Backup files are created periodically to prevent data loss.

## Building from Source

### CMake Build (Recommended)
```bash
# Debug build
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make

# Release build
mkdir build-release
cd build-release
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

### CMake Build Options
```bash
# Enable testing
cmake -DBUILD_TESTS=ON ..

# Set custom install directory
cmake -DCMAKE_INSTALL_PREFIX=/custom/path ..

# Verbose build output
make VERBOSE=1
```

## Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/new-feature`)
3. Commit your changes (`git commit -am 'Add new feature'`)
4. Push to the branch (`git push origin feature/new-feature`)
5. Create a Pull Request

## Testing

Run the included unit tests using CMake:
```bash
cd build
cmake -DBUILD_TESTS=ON ..
make
ctest --verbose
```

Or run tests manually:
```bash
cd build
./tests/test_manager
```

## Future Enhancements

- GUI interface using Qt or similar framework
- Database integration (SQLite/MySQL)
- Email integration for application reminders
- Analytics and reporting features
- Cloud synchronization capabilities
- Mobile app companion

## Troubleshooting

**Common Issues:**

- **File Permission Errors**: Ensure write permissions in the data directory
- **Compilation Errors**: Verify C++11 support and proper include paths
- **Data Corruption**: Use backup files located in `data/backups/`

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Author

Kaan Ismet Okul | KaanIsmet7@gmail.com

## Changelog

### v1.0.0 (Current)
- Initial release with basic CRUD functionality
- File-based data persistence
- Console interface implementation
- Search and filter capabilities
- C++20 standard compliance
- CMake build system integration

---

For detailed usage instructions and API documentation, please refer to the `docs/` directory.
